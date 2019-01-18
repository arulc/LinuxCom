#include "includes.h"

#define DELAY_TIME (1)

#define MYSFIFO ("/tmp/myfifo")
#define DEF_FIFODATABUF_SIZE PIPE_BUF

int test_fifo1(void)
{
    pid_t pid;
    int pipe_fd[2];
    char buf[DEF_DATABUF_SIZE];
    const char *data = "pipi test progran\n";
    const char *data1 = "child info to send\n";
    int rread, rwrite;
    int i = 0;

    memset(buf, 0x00, sizeof(buf));
    if (pipe(pipe_fd) < 0)
    {
        printf("pipe create error \n");
        exit(1);
    }
    pid = fork();
    if (pid == 0)
    {

        // sleep(DELAY_TIME * 3);

        rread = read(pipe_fd[0], buf, DEF_DATABUF_SIZE);
        if (rread > 0)
        {
            printf("%d bytes read from the pipe is '%s' \n", rread, buf);
        }
        rwrite = write(pipe_fd[1], data1, strlen(data1));
        if (rwrite != -1)
        {
            printf("childe wrote %d bytes: %s\n", rwrite, data1);
        }
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        exit(0);
    }
    else if (pid > 0)
    {

        sleep(DELAY_TIME);
        for (i = 0; i < 100; i++)
        {
            rwrite = write(pipe_fd[1], data, strlen(data));
            if (rwrite != -1)
            {
                printf("parent wrote %d bytes : %s \n", rwrite, data);
            }
        }

        close(pipe_fd[0]);
        close(pipe_fd[1]);
        waitpid(pid, NULL, 0);
        rread = read(pipe_fd[0], buf, DEF_DATABUF_SIZE);
        if (rread > 0)
        {
            printf("%d bytes read from the childe dpipe is '%s' \n", rread, buf);
        }
        exit(0);
    }
}

#define BUFSIZE (1024)
int test_fifo2(void)
{
    FILE *fp;
    char *cmd = "ps -ef";
    char buf[BUFSIZE];

    fp = popen(cmd, "r");
    if (fp == NULL)
    {
        printf("popen error \n");
        exit(1);
    }
    while (fgets(buf, BUFSIZE, fp) != NULL)
    {
        printf("%s", buf);
    }
    pclose(fp);
    exit(0);
}

int test_forksem(void)
{
    pid_t res;
    int sem_id;

    sem_id = semget(ftok(".", 'a'), 1, 0666 | IPC_CREAT);
    init_sem(sem_id, 0);

    res = fork();
    if (res == -1)
    {
        perror("Fork\n");
    }
    else if (res == 0)
    {
        printf("Child process will wait for some seconds...\n");
        sleep(3);
        printf("The returned value is %d in the child  process (PID = %d)\n", res, getpid());
        sem_v(sem_id);
    }
    else
    {
        sem_p(sem_id);
        printf("The returned value is %d in the parent process (PID = %d)\n", res, getpid());
        sem_v(sem_id);
        del_sem(sem_id);
    }
    exit(0);
}
