#include <idtcpu.h>			/* Definierar CPU-beroende symboler */
#include <iregdef.h>		/* Definierar registernamn */

	.text

	.set noreorder
	.set noat


	/* 
	ITS_store_state stores the current threads
	context to the stack.
	The kernel registers (k0/k1) are not stored.
	Kernel register k0 points at the current TCB
	*/		

	.globl ITS_store_state
	.ent ITS_store_state
ITS_store_state:
	# store "normal" registers to stack
	sw	AT, R_AT*4(k0)
	sw	v0, R_V0*4(k0)
	sw	v1, R_V1*4(k0)
	sw	a0, R_A0*4(k0)
	sw	a1, R_A1*4(k0)
	sw	a2, R_A2*4(k0)
	sw	a3, R_A3*4(k0)
	sw	t0, R_T0*4(k0)
	sw	t1, R_T1*4(k0)
	sw	t2, R_T2*4(k0)
	sw	t3, R_T3*4(k0)
	sw	t4, R_T4*4(k0)
	sw	t5, R_T5*4(k0)
	sw	t6, R_T6*4(k0)
	sw	t7, R_T7*4(k0)
	sw	s0, R_S0*4(k0)
	sw	s1, R_S1*4(k0)
	sw	s2, R_S2*4(k0)
	sw	s3, R_S3*4(k0)
	sw	s4, R_S4*4(k0)
	sw	s5, R_S5*4(k0)
	sw	s6, R_S6*4(k0)
	sw	s7, R_S7*4(k0)
	sw	t8, R_T8*4(k0)
	sw	t9, R_T9*4(k0)
	sw	gp, R_GP*4(k0)
	sw	sp, R_SP*4(k0)
	sw	fp, R_FP*4(k0)
	sw	ra, R_RA*4(k0)

	# now we are free to use the 
	# registers as we see fit.

	# store EPC
	mfc0	t0, C0_EPC
	nop
	sw		t0, R_EPC*4(k0)
	
	# store LO/HI	
	mflo	t0
	mfhi	t1
	sw		t0, R_MDHI*4(k0)
	sw		t1, R_MDLO*4(k0)

	# Jump to main scheduler function
	# A pointer to the current threads TCB, k0, is the argument
	# ITS_scheduler returns the address to the new TCB
	jal		ITS_scheduler
	move 	a0,k0
	
	move	k0,v0
	
	# restore MDHI/MDLO
	lw	t0,R_MDHI*4(k0)
	lw	t1,R_MDLO*4(k0)
	mtlo	t0
	mthi	t1

	# load "normal" registers from TCB
	lw	AT, R_AT*4(k0)
	lw	v0, R_V0*4(k0)
	lw	v1, R_V1*4(k0)
	lw	a0, R_A0*4(k0)
	lw	a1, R_A1*4(k0)
	lw	a2, R_A2*4(k0)
	lw	a3, R_A3*4(k0)
	lw	t0, R_T0*4(k0)
	lw	t1, R_T1*4(k0)
	lw	t2, R_T2*4(k0)
	lw	t3, R_T3*4(k0)
	lw	t4, R_T4*4(k0)
	lw	t5, R_T5*4(k0)
	lw	t6, R_T6*4(k0)
	lw	t7, R_T7*4(k0)
	lw	s0, R_S0*4(k0)
	lw	s1, R_S1*4(k0)
	lw	s2, R_S2*4(k0)
	lw	s3, R_S3*4(k0)
	lw	s4, R_S4*4(k0)
	lw	s5, R_S5*4(k0)
	lw	s6, R_S6*4(k0)
	lw	s7, R_S7*4(k0)
	lw	t8, R_T8*4(k0)
	lw	t9, R_T9*4(k0)
	lw	gp, R_GP*4(k0)
	lw	sp, R_SP*4(k0)
	lw	fp, R_FP*4(k0)
	lw	ra, R_RA*4(k0)

	# load EPC 
	lw	k1,R_EPC*4(k0)
	nop
	
	# return
	jr	k1
	rfe					# This must be executed in the jump delay slot of jr.

	.end ITS_store_state


/*
	ITS_intstub is used to replace the normal
	interrupt handler.	
*/

ITS_intstub:
	j	ITS_store_state
	nop


	.globl ITS_init_handler
	.ent ITS_init_handler
ITS_init_handler:
	la 	t0,0x80000080	# dst
	la	t1,ITS_intstub	# src
	
	lw	t2,0(t1)
	lw	t3,4(t1)

	sw	t2,0(t0)
	sw	t3,4(t0)

	jr	ra
	nop
	.end ITS_init_handler
	
