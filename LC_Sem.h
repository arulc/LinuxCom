#ifndef LC_Sem_H
#define LC_Sem_H


extern int init_sem(int sem_id, int init_value);

extern int del_sem(int sem_id);

extern int sem_p(int sem_id);

extern int sem_v(int sem_id);

#endif

