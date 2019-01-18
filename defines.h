#ifndef DEFINES_H
#define DEFINES_H

#define DEF_DATABUF_SIZE (256)

#define BUFFER_SIZE (1024)

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

struct message
{
    long msg_type;
    char msg_text[BUFFER_SIZE];
};

#endif
