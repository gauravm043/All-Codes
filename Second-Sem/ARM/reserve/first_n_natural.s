@ SUM OF FIRST N NATURAL NUMBERS
	.text

main:
		mov r1, #0			@ SUM
		mov r2, #5			@ COUNTER
		bl sum
		b exit

sum:
		cmp r2, #0
		moveq pc,lr

		add r1,r1,r2
		sub r2,r2,#1

		sub sp,sp,#4
		str lr,[sp]
		bl sum
		ldr lr,[sp]
		add sp,sp,#4
		mov pc,lr

exit:
		mov r0,#0
		mov r7,#1
		svc 0x00000000
