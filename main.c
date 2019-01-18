
#include "includes.h"

int test_fork()
{
    pid_t res;

    res = fork();
    printFLV(res);
    if (-1 == res)
    {
        // printf("Error");
        perror("Fork Create");
    }
    else if (0 == res) //子进程
    {
        printf("Child process, res = %d, PID = %d\n", res, getpid());
        // while (1)
        // {

        //     ;
        // }
        // execlp("ps", "ps", "-elf", NULL);
    }
    else //父进程
    {
        printf("Father process, res = %d, PID = %d\n", res, getpid());
    }
    printLN;

    perror("Fork Create");
    printf("Success\n");

    return res;
}

int test_wait()
{
    pid_t pc, pr, pc1;
    int res = 0;

    pc = fork();
    printFLV(pc);
    if (pc < 0)
    {
        // printf("Error");
        perror("Fork Create");
    }
    else if (0 == pc) //子进程
    {

        printf("Child process, res = %d, PID = %d\n", pc, getpid());
        sleep(5);
        printf("Child processdown\n");

        exit(22);
    }
    else //父进程
    {
        pc1 = fork();
        if (pc == 0)
        {
            sleep(10);

            printf("===>The second fork \n");
            printf("Child process, res = %d, PID = %d\n", pc, getpid());
        }
        else
        {
            printf("Father process, res = %d, PID = %d\n", res, getpid());
        }

        // do
        // {
        //     printf("pc = %d\n", pc);
        //     pr = waitpid(pc, &res, WUNTRACED);
        //     printf("res = %d \n", (res >> 8));
        //     if (pr == 0)
        //     {
        //         printf("The child process has not exited  \n");
        //         sleep(1);
        //     }
        // } while (0 == pr);
    }
    // printFLV();
    if (pr == pc)
    {
        printf("Get child exxit code: %d\n", pr);
    }
    else
    {
        printf("Some error occured.\n");
    }
    _printf("===>%s()--L:%d \n", __FUNCTION__, __LINE__);
    printf("===>%s()--L:%d \n", __FUNCTION__, __LINE__);
    printf("Fork Create\n");
    printf("Success\n");

    return pc;
}
int test_exit()
{
    printf("aaaaaaaaaaaaaaaaaaaaaaa");
    exit(1);
}
int main(void)
{
    return test_pthread();
    return 0;
}