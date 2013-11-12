@nth fibonacci number will be stored in r3 and we will give the value of n in r0 at start
.text
main:
	mov r0,#7
	sub sp,sp,#4
	str lr,[sp]
	bl f
	ldr lr,[sp]
	add sp,sp,#4
	b exit
f:
	cmp r0,#0
	moveq r3,#0
	moveq pc,lr
	cmp r0,#1
	moveq r3,#1
	moveq pc,lr
	sub r0,r0,#1
	mov r4,r0
	sub sp,sp,#8
	str r4,[sp,#4]
	str lr,[sp]
	bl f
	ldr lr,[sp]
	ldr r4,[sp,#4]
	add sp,sp,#8
	mov r5,r3
	sub r4,r4,#1
	mov r0,r4
	stmfd sp!,{r5,lr}	@put r5,lr on top of the stack and decrease sp accordingly
	bl f
	ldmfd sp!,{r5,lr}
	add r3,r5,r3
	mov pc,lr
exit:
	mov r0,#0
	mov r7,#1
	svc 0x00000000
