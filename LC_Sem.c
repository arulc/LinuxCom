
/**
 * 
 * sem_com.c
 */

#include "includes.h"

int init_sem(int sem_id, int init_value)
{
    union semun sem_union;
    sem_union.val = init_value;
    int res;
    res = semctl(sem_id, 0, SETVAL, sem_union);
    if (res == -1)
    {
        perror("Initialize semaphore");
        printLN;

        return -1;
    }
    return 0;
}

int del_sem(int sem_id)
{
    union semun sem_union;
    int res;
    res = semctl(sem_id, 0, IPC_RMID, sem_union);

    if (res == -1)
    {
        perror("Delete semaphore");
        printLN;
        return -1;
    }
    return 0;
}

int sem_p(int sem_id)
{
    struct sembuf sem_b;
    int res;

    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;

    res = semop(sem_id, &sem_b, 1);
    if (res == -1)
    {
        perror("P operation");
        printLN;

        return -1;
    }
    return 0;
}

int sem_v(int sem_id)
{
    struct sembuf sem_b;
    int res;

    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;

    res = semop(sem_id, &sem_b, 1);
    if (res == -1)
    {
        perror("V operation");
        printLN;

        return -1;
    }
    return 0;
}
