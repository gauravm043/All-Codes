@ FACTORIAL OF A NUMBER
	.text

main:
		mov r4,#1
		mov r2, #12		@ NUMBER WHOSE FACTORIAL YOU WANT
		bl fact
		b exit

fact:
		sub r2,r2,#1
		cmp r2, #1
		moveq pc,lr
		stmfd sp!,{r2,lr}
		bl fact
		ldmfd sp!,{r2,lr}
		mov r1,r4

multi:
		sub r2,r2,#1
		cmp r2,#1
		beq return
		add r4,r4,r1
		b multi
		
		
return:
		mov pc,lr

exit:
		mov r0,#0
		mov r7,#1
		svc 0x00000000
