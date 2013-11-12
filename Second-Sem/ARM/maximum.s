@PROGRAM TO CALCULATE THE MAXIMUM NUMBER IN AN ARRAY
	.text


entry:		
		ldr r2, =arr
		ldr r3, =eoa
		ldrb r1, [r2], #1 

loop:

		ldrb r4, [r2], #1
		cmp r4, r1
		movgt r1, r4
		cmp r2, r3
		bne loop

stop:
		mov r0, #0
		mov r7, #1
		svc 0x00000000

arr: .byte 99, 36, 3, 4, 240, 100, 169, 56
eoa:
