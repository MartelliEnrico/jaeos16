#pragma once

#include <uARMtypes.h>

#include "clist.h"
#include "const.h"

typedef unsigned int pid_t;
typedef unsigned int cputime_t;

struct semd_t {
    int *s_semAdd; /* pointer to the semaphore */
    struct clist s_link; /* ASL linked list */
    struct clist s_procq; /* blocked process queue */
};

/* process control block type */
struct pcb_t {
    struct pcb_t *p_parent; /* pointer to parent */
    struct semd_t *p_cursem; /* pointer to the semd_t on
                    which process blocked */
    pid_t p_pid;
    cputime_t p_time;
    state_t p_s; /* processor state */
    state_t p_excpvec[EXCP_COUNT]; /*exception states vector*/
    struct clist p_list; /* process list */
    struct clist p_children; /* children list entry point*/
    struct clist p_siblings; /* children list: links to the siblings */
};