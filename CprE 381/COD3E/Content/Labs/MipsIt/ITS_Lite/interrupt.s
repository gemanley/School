#include <idtcpu.h>
#include <iregdef.h>
#include <excepthdr.h>

#define INTERRUPT		0xbfa00000
#define PIO_SETUP2		0xffffea2a

/**********************
* init_ext_int
***********************/
	.globl	init_ext_int
	.ent		init_ext_int
	.set		noreorder

init_ext_int:
	# push ra
	sw		ra, 0(sp)
	sub		sp, 4

	# set pin 3 as interrupt
	lh		a0, PIO_SETUP2
	nop
	andi	a0, 0xbfff
	sh		a0, PIO_SETUP2

	# clear spurious interrupts
	# clear interrupt 3
init_ext_int_loop1:
	sb		r0, INTERRUPT
	jal		get_CAUSE
	nop
	andi	v0, EXT_INT3
	bne		v0, r0, init_ext_int_loop1

	# pop ra
	addi	sp, 4
	lw		ra, 0(sp)
	nop

	jr		ra
	nop

	.set	reorder
	.end	init_ext_int

/*************************************
*	unsigned int get_CAUSE();
**************************************/
	.globl	get_CAUSE
	.ent	get_CAUSE
	.set	noreorder

get_CAUSE:
	mfc0	v0, C0_CAUSE
	nop

	jr		ra
	nop

	.set	reorder
	.end	get_CAUSE


/*************************************
*	set_CAUSE(unsigned int);
**************************************/
	.globl	set_CAUSE
	.ent	set_CAUSE
	.set	noreorder

set_CAUSE:
	mtc0	a0, C0_CAUSE
	nop

	jr		ra
	nop

	.set	reorder
	.end	set_CAUSE


/*************************************
*	void enable_int(unsigned int);
**************************************/
	.globl	enable_int
	.ent	enable_int
	.set	noreorder

enable_int:
	
	mfc0	v0, C0_SR
	nop
	ori		v0, 1
	or		v0, a0
	mtc0	v0, C0_SR
	nop

	jr		ra
	nop

	.set	reorder
	.end	enable_int


/*************************************
*	void disable_int(unsigned int);
**************************************/
	.globl	disable_int
	.ent	disable_int
	.set	noreorder

disable_int:
	
	mfc0	v0, C0_SR
	nop
	not		a0
	ori		a0, 0xff
	and		v0, a0
	mtc0	v0, C0_SR
	nop

	jr		ra
	nop

	.set	reorder
	.end	disable_int


/*************************************
*	void acknowledge_int(unsigned int);
**************************************/
	.globl	acknowledge_int
	.ent	acknowledge_int
	

acknowledge_int:
	
1:
	sw		zero, INTERRUPT
	mfc0	t0, C0_CAUSE
	nop
	and		t0,a0			# Check if interrupt has been acknowledged
	bne		t0,zero,1b		# Loop if not

	jr		ra
	
	.end	acknowledge_int


/*************************************
*	void do_syscall(unsigned int);
	The argument (a0) is passed on to the interrupt routine.
**************************************/
	.globl	do_syscall
	.ent	do_syscall
	
do_syscall:

	syscall	
	jr		ra
	
	.end	acknowledge_int


