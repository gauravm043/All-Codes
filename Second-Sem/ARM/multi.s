	.text
main:
		mov r0,#3
		mov r1,#15
		mul r1,r0,r1
exit:
		mov r0,#0
		mov r7,#7
		svc 0x00000000
