#ifndef _IT_SCHED_H_
#define _IT_SCHED_H_

typedef unsigned int uint;
typedef unsigned char byte;

/* Defined in it_sched.c */
extern void ITS_init();
extern uint ITS_create_thread( void (*entry)(void *), void *arg, uint *stack_top);
extern void ITS_enter_critical();
extern void ITS_leave_critical();
extern void ITS_yield();


#endif
