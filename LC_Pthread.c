#include "includes.h"

#define DEF_PthreadNum (3)
#define DEF_RepeatNum (3)
#define DEF_DelayTime (3.0)

pthread_mutex_t mutex;

void *fun(void *arg)
{
    int thrd_num = (int)arg;
    int delay_time = 0;
    int count = 0;
    int res;
    PRINTHead;
    printFLV(RAND_MAX);
    printFLV(rand());
    res = pthread_mutex_lock(&mutex);
    if (res)
    {
        printf("Thread %d lock failed \n", thrd_num);
         res = pthread_mutex_unlock(&mutex);
        pthread_exit(thrd_num);
    }

    for (count = 0; count < DEF_RepeatNum; count++)
    {
        delay_time = (int)((rand() * DEF_DelayTime) / (RAND_MAX)) + 1;
        printf("===> Thread %d : job %d delay = %d\n", thrd_num, count, delay_time);

        sleep(delay_time);
    }
    printf("==> Thread %d finished \n", thrd_num);
     res = pthread_mutex_unlock(&mutex);
    pthread_exit(thrd_num);
}

int test_pthread(void)
{
    pthread_t thread[DEF_PthreadNum];

    void *thrd_res;
    int res, no;

    pthread_mutex_init(&mutex, NULL);

    srand(time(NULL));
    for (no = 0; no < DEF_PthreadNum; no++)
    {
        res = pthread_create(&thread[no], NULL, fun, (void *)no);
        if (res != 0)
        {
            printf("Create thread %d failed \n", no);
            return res;
        }
    }

    for (no = 0; no < DEF_PthreadNum; no++)
    {
        res = pthread_join(thread[no], &thrd_res);
        if (res != 0)
        {
            printf("thread  %d  join failed \n", no);
            exit(res);
        }
        else
        {
            printf("thread  %d  join succ \n", no);
        }
        res = pthread_mutex_unlock(&mutex);
        {
            printFLV(res);
        }
    }
    return 0;
}
