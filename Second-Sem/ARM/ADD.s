@   		PROGRAM TO ADD 2 NO.S

.text


main:
	mov r0, #5
	mov r1, #9
	bl sum
	b stop

sum:
	add r3,r0,r1
	mov pc,lr

stop:
	mov r0, #0
	mov r7, #1
	svc 0x00000000
