#include <excepthdr.h>
#include <iregdef.h>
#include "its.h"
#include "util.h"

#define MAX_THREADS 16

/* Thread Control Block allocated for each thread */
/* Define a new type TCB */
typedef struct TCB_ {
	uint registers[NREGS];			/* area where registers are saved */
	int id;
} TCB;

TCB  threads[MAX_THREADS];		/* a TCB for each thread */
uint thread_count;				/* The current number of threads */
uint current_thread;			/* The identity of the currently running thread */


/*
	Main scheduler function.
	Called from interrupt handler.
	Argument:
		syscall_arg - Argument to a potential system call
		tcb - A pointer to the current thread's TCB.
*/

TCB *ITS_scheduler(TCB  *tcb)
{
	uint cause;
		
	/* Check interrupt source 
	   We are only interested in EXT_INT3 and EXC_SYSCALL */
	cause = get_CAUSE();
	if ( cause & EXT_INT3 )
	{
		/* acknowledge external int 3 */
		acknowledge_int(EXT_INT3);
	} else if ( cause & SW_INT0 )
	{
		/* acknowledge sw int 0 */
		set_CAUSE(0);
	} else {
		return 0;
	}

	
	/* select next thread to run. Round robin: */
	current_thread = (current_thread + 1) % thread_count;
	
	/* Return the new thread's TCB. */

	return &(threads[current_thread]);
}

/*	void ITS_init(void)
	
	Initialize the sceduler.
	Note: Converts the calling function to thread 0.
*/

void ITS_init()
{
	thread_count = 1;
	current_thread = 0;

	/* Set k0 to point to the current thread TCB */
	set_k0((uint) &(threads[0]));
	threads[0].id = 0;

	/* Initialises the interrupt handler */
	ITS_init_handler();
	init_ext_int();
	enable_int(EXT_INT3 | SW_INT0);
}

/*
	uint ITS_create_thread(entry, arg, stack_top)
	
	Creates a new thread and adds it to the sceduler.
	Arguments:
		entry - Entry point
		arg - Pointer to the argument to the new thread. One argument is allowed.
		stack_top - Address to top of stack
		
	Returns:
		The identity of the newly created thread. Zero if it fails.
*/

uint ITS_create_thread( void (*entry)(void *), void *arg, uint *stack_top) {	
	TCB *new_tcb;

	disable_int(EXT_INT3 | SW_INT0);
	
	/* Have we got space for another thread? */
	if (thread_count >= MAX_THREADS)
		return 0;

	new_tcb = &(threads[thread_count]);

	/* Set initial stack pointer for the thread. It starts
	   at a high address and grows to lower addresses. */
	new_tcb->registers[R_SP] = (uint) stack_top;

	/* Set some registers on the stack. */
	/* gp (gcc needs this) */
	new_tcb->registers[R_GP] = get_gp();

	/* fp (gcc needs this) */
	new_tcb->registers[R_FP] = get_fp();

	/* epc (thread entry point) */
	new_tcb->registers[R_EPC] = (uint) entry;

	/* a0 (thread argument) */
	new_tcb->registers[R_A0] = (uint) arg;

	thread_count++;
	
	enable_int(EXT_INT3 | SW_INT0);	

	return (thread_count-1);
}

/*
	Enter a critical section. Must be paired with a LeaveCritical()
*/
void ITS_enter_critical() {
	disable_int(EXT_INT3 | SW_INT0);
}

/*
	Leave a critical section
*/
void ITS_leave_critical() {
	enable_int(EXT_INT3 | SW_INT0);
}

/*
	Yield the processor to another thread.
*/
void ITS_yield() {
	set_CAUSE(SW_INT0);
}