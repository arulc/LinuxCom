#ifndef INCLUDES_H
#define INCLUDES_H

/**
 * 系统
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <error.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <pthread.h>
// #include <.h>

/**
 * 用户
 */

#include "defines.h"
#include "LC_Debug.h"




// sector7.c
extern int test_case2(void );

#endif
