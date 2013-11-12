	.text

main:
		mov r0, #100
		mov r1, #0
		stmfd sp!,{r0,lr}
		bl sum
		ldmfd sp!,{r0,lr}
		add r1,r1,r0
		b exit

sum:
		cmp r0, #1
		moveq pc,lr
		sub r0,r0,#1
		stmfd sp!,{r0,lr}
		bl sum
		ldmfd sp!,{r0,lr}
		add r1,r1,r0
		mov pc,lr

exit:
		mov r0,#0
		mov r7,#1
		svc 0x00000000
