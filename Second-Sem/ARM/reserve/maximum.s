@PROGRAM TO CALCULATE THE MAXIMUM NUMBER IN AN ARRAY
	.text


main:		

		ldr r2, =arr
		ldr r3, =eoa
		ldr r1,[r2]

loop:

		ldr r4,[r2],#1
		cmp r4,r1
		movlt r1,r4
		cmp r4,r3
		bne loop

stop:
		mov r0,#0
		mov r7,#1
		svc 0x00000000

arr:		.byte 1 2 3 4 100 169 56
eoa:
