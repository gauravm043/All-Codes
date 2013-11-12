@ PROGRAM TO ADD THE NOS USING A FUNCTION
@ a version of passing 2 arguments in c 2 a fun and returning a sum
@ arguments are passed in a stack
@ need to store the addresses in a link registers 
@but values or addresses are to be putted in a stack else add. lost in recursion

	.text

.global main

add:
	ldr r0,[sp]				@need to pop 2 arg since stack grows upwards and popping increases the addresses
	ldr r1,[sp, #4]				
	add sp , sp, #8
	add r2,r0,r1
	sub sp, sp, #4
	str r2,[sp]
	mov pc,lr








main:
	mov r0, #5
	mov r1, #4
	sub sp, sp, #4				@pushing means stack add grows backwards decreases in add values
	str lr, [sp]
	sub sp, sp, #8
	str r0, [sp]
	str r1, [sp,#4]
	bl add
	ldr r3,[sp]
	ldr lr,[sp,#4]
	add sp, sp, #8




