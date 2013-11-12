@THE PROGRAM IS LOADED IN THE MEMORY AND EOA AND ARR ARE ACTUAL ADDRESSES AT THE TIME OF EXECUTION

@find the sum of an array
	.text
entry:
	ldr r0, =eoa		@r0=&eoa
	ldr r1, =arr		@r1=&arr
	mov r3, #0		@r3=0
loop:
	ldrb r2,[r1],#1 	@r2=*r1++
	add r3,r2,r3		@r3+=r3
	cmp r1,r0		@if(r1!=r2)
        bne loop		@goto loop
stop:
	mov r0, #0		@return code like return 0 in c
	mov r7, #1		@sys exit arm exits
	svc 0x00000000		@it means software interupt look for r0

arr: 	.byte 10,20,25		@read only array of bytes
eoa:				@address of end of array + 1
