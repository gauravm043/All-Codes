@   		PROGRAM TO ADD 2 NO.S

		.text


main:
	mov r0, #5
	mov r1, #9
	add sp,sp, #8
	str r0, [sp]
	sub sp,sp, #4
	str r1,[sp]
	sub sp,sp,#4
	str lr,[sp]
	bl add
	ldr r1,[sp]

add:
	ldr r7,[sp,#4]
	ldr r8,[sp,#8]
	add r7,r7,r8
	ldr lr,[sp]
	str r7,[sp]
	mov pc,lr
