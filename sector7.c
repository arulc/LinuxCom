#include "includes.h"

int test_case2(void)
{
    pid_t child1, child2;
    int i;

    child1 = fork();
    if (child1 == 1)
    {
        perror("child1 fork");
        exit(1);
    }
    else if (child1 > 0)
    {

        exit(0);
    }
    else
    {
        ;
    }
    openlog("daemon_proc_info", LOG_PID, LOG_DAEMON);
    setsid();
    umask(0);
    for (i = 0; i < getdtablesize(); i++)
    {
        close(i);
    }

    child2 = fork();
    if (child2 == 1)
    {
    }
    else if (child2 == 0)
    {
        syslog(LOG_INFO, "child2 will sleep for 10s");
        sleep(10);
        syslog(LOG_INFO, "child2 is going to exit!");
        exit(0);
    }
    else
    {
        waitpid(child2, NULL, 0);
        syslog(LOG_INFO,"child1 noticed that child2 has exited ");
        closelog();
        while(1)
        {
            sleep(10);
        }
    }
}