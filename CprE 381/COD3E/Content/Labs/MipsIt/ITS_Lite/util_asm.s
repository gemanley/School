/******************************************************

Some assembler utitilites to get and set values of 
processor registers. The following functions are
available:

uint get_sp();		Get the value of sp
uint get_gp();		Get the value of gp
uint fet_fp();		Get the value of fp
uint get_k0();		Get the value of k0
void set_k0(uint);	Set the value of k0

*******************************************************/
#include <iregdef.h>

	.text
	.set reorder
	.set at

/*
	uint get_sp(void)
	returns the stack pointer.
*/

	.globl get_sp
	.ent get_sp
get_sp:
	move	v0,sp
	jr		ra

	.end get_sp

/*
	uint get_gp(void)
	returns the gp register
*/

	.globl get_gp
	.ent get_gp
get_gp:
	move	v0,gp
	jr		ra

	.end get_gp

/*
	uint get_fp(void)
	returns the fp register
*/

	.globl get_fp
	.ent get_fp
get_fp:
	move	v0,fp
	jr		ra

	.end get_fp

/*
	uint get_k0(void)
	returns register k0.
*/

	.globl get_k0
	.ent get_k0
get_k0:
	move	v0,k0
	jr		ra

	.end get_k0


/*
	void set_k0(uint new_k0)
	set register k0 to new value.
*/

	.globl set_k0
	.ent set_k0
set_k0:
	move	k0,a0
	jr		ra

	.end set_k0
	