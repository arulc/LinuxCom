#include "includes.h"

int test_msg(void)
{
    int qid;
    key_t key;
    struct message msg;
    int res;
    void *pres;
    int pid;
    char *content = "asdfadsfoashfafd\n";
    pid = fork();
    if (pid < 0)
    {
        perror("Fork create");
    }
    else if (0 == pid) //child process
    {
        printf("child pid = %d \n", getpid());

        key = ftok(".", 'a');
        if (-1 == key)
        {
            perror("ftok");
            exit(1);
        }
        qid = msgget(key, IPC_CREAT | 0666);
        if (-1 == qid)
        {
            perror("msgget");
            exit(1);
        }
        printf("Open queue %d \n", qid);


        do
        {
             memset(&msg, 0x00, sizeof(msg));
            
            res = msgrcv(qid, &msg, BUFFER_SIZE, 0, 0);
            if (res < 0)
            {
                perror("msg recv");
                exit(1);
            }
            printf("Child recv msg, type = %d , content:%s\n", msg.msg_type, msg.msg_text);
            system(msg.msg_text);
        } while (strncmp(msg.msg_text, "quit", 4) != 0);

        res = msgctl(qid, IPC_RMID, NULL);
        if (res < 0)
        {
            perror("rm msg");
            exit(1);
        }
        perror("child process exit");

        exit(0);
    }
    else //father process
    {
        printf("father pid = %d \n", getpid());
        key = ftok(".", 'a');
        if (-1 == key)
        {
            perror("ftok");
            exit(1);
        }

        qid = msgget(key, IPC_CREAT | 0666);
        if (-1 == qid)
        {
            perror("msgget");
            exit(1);
        }
        printf("Open queue %d \n", qid);

        while (1)
        {
            printf("Enter some message to the quequ:\n");
            memset(&msg, 0x00, sizeof(msg));

            pres = fgets(msg.msg_text, BUFFER_SIZE, stdin);
            if (NULL == pres)
            {
                puts("No message");
                exit(1);
            }

            msg.msg_type = getpid();

            msg.msg_type = 15;
            memcpy(msg.msg_text, content, strlen(content));

            res = msgsnd(qid, &msg, strlen(msg.msg_text), 0);
            if (res < 0)
            {
                perror("Message posted");
                exit(1);
            }

            res = strncmp(msg.msg_text, "quit", 4);
            if (0 == res)
            {
                break;
            }
        }
        wait(NULL);
        perror("father process exit");
        exit(0);
    }
}