	.file	"sudoku_solver.c"
	.comm	arr,1600,32
	.globl	UNI
	.data
	.align 4
	.type	UNI, @object
	.size	UNI, 4
UNI:
	.long	1
	.comm	R,4,4
	.section	.rodata
.LC0:
	.string	"%d"
	.align 4
.LC1:
	.string	"YOU HAVE ENTERED AN INVALID SUDOKU"
.LC2:
	.string	"SOLVED SUDOKU IS="
.LC3:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$64, %esp
	movl	$0, 56(%esp)
	movl	$0, 60(%esp)
	leal	44(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	movl	44(%esp), %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fstpl	(%esp)
	call	sqrt
	fnstcw	26(%esp)
	movzwl	26(%esp), %eax
	movb	$12, %ah
	movw	%ax, 24(%esp)
	fldcw	24(%esp)
	fistpl	28(%esp)
	fldcw	26(%esp)
	movl	28(%esp), %eax
	movl	%eax, R
	movl	$0, 48(%esp)
	jmp	.L2
.L5:
	movl	$0, 52(%esp)
	jmp	.L3
.L4:
	movl	48(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	52(%esp), %edx
	addl	%edx, %eax
	sall	$2, %eax
	addl	$arr, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	addl	$1, 52(%esp)
.L3:
	movl	44(%esp), %eax
	cmpl	%eax, 52(%esp)
	jl	.L4
	addl	$1, 48(%esp)
.L2:
	movl	44(%esp), %eax
	cmpl	%eax, 48(%esp)
	jl	.L5
	movl	$0, 48(%esp)
	jmp	.L6
.L10:
	movl	$0, 52(%esp)
	jmp	.L7
.L9:
	movl	48(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	52(%esp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	testl	%eax, %eax
	jne	.L8
	movl	48(%esp), %eax
	movl	%eax, 56(%esp)
	movl	52(%esp), %eax
	movl	%eax, 60(%esp)
	movl	44(%esp), %eax
	movl	%eax, 8(%esp)
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	solve
.L8:
	addl	$1, 52(%esp)
.L7:
	movl	44(%esp), %eax
	cmpl	%eax, 52(%esp)
	jl	.L9
	addl	$1, 48(%esp)
.L6:
	movl	44(%esp), %eax
	cmpl	%eax, 48(%esp)
	jl	.L10
	movl	56(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	60(%esp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	testl	%eax, %eax
	jne	.L11
	movl	$.LC1, (%esp)
	call	puts
	movl	$0, %eax
	jmp	.L17
.L11:
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, 48(%esp)
	jmp	.L13
.L16:
	movl	$0, 52(%esp)
	jmp	.L14
.L15:
	movl	48(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	52(%esp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	addl	$1, 52(%esp)
.L14:
	movl	44(%esp), %eax
	cmpl	%eax, 52(%esp)
	jl	.L15
	movl	$10, (%esp)
	call	putchar
	addl	$1, 48(%esp)
.L13:
	movl	44(%esp), %eax
	cmpl	%eax, 48(%esp)
	jl	.L16
	movl	$0, %eax
.L17:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	solve
	.type	solve, @function
solve:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$0, -28(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -20(%ebp)
	jmp	.L20
.L23:
	addl	$1, -28(%ebp)
	movl	16(%ebp), %eax
	addl	$1, %eax
	cmpl	-28(%ebp), %eax
	jne	.L21
	movl	$0, UNI
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	12(%ebp), %edx
	addl	%edx, %eax
	movl	$0, arr(,%eax,4)
	jmp	.L18
.L21:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	12(%ebp), %edx
	addl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%eax, arr(,%edx,4)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	check_it
	movl	%eax, -20(%ebp)
.L20:
	cmpl	$0, -20(%ebp)
	je	.L23
	movl	$0, -16(%ebp)
	jmp	.L24
.L31:
	movl	$0, -12(%ebp)
	jmp	.L25
.L28:
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	testl	%eax, %eax
	jne	.L26
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	solve
	movl	UNI, %eax
	testl	%eax, %eax
	jne	.L26
	movl	$1, UNI
	movl	$1, -24(%ebp)
	jmp	.L27
.L26:
	addl	$1, -12(%ebp)
.L25:
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	.L28
.L27:
	cmpl	$1, -24(%ebp)
	je	.L33
.L29:
	addl	$1, -16(%ebp)
.L24:
	movl	-16(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	.L31
	jmp	.L30
.L33:
	nop
.L30:
	cmpl	$1, -24(%ebp)
	jne	.L34
	movl	$0, -24(%ebp)
	movl	$0, -20(%ebp)
	nop
.L19:
	jmp	.L20
.L34:
	nop
.L18:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	solve, .-solve
	.globl	check_it
	.type	check_it, @function
check_it:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	12(%ebp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	cmpl	16(%ebp), %eax
	jle	.L36
	movl	$0, %eax
	jmp	.L37
.L36:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	12(%ebp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	movl	%eax, -4(%ebp)
	movl	$0, -20(%ebp)
	jmp	.L38
.L41:
	movl	-20(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	.L39
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	-20(%ebp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	cmpl	-4(%ebp), %eax
	jne	.L39
	movl	$0, %eax
	jmp	.L37
.L39:
	movl	-20(%ebp), %eax
	cmpl	8(%ebp), %eax
	je	.L40
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	12(%ebp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	cmpl	-4(%ebp), %eax
	jne	.L40
	movl	$0, %eax
	jmp	.L37
.L40:
	addl	$1, -20(%ebp)
.L38:
	movl	-20(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	.L41
	movl	$0, -20(%ebp)
	jmp	.L42
.L47:
	movl	-20(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	.L43
.L46:
	movl	8(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jne	.L44
	movl	-20(%ebp), %eax
	movl	%eax, -12(%ebp)
.L44:
	movl	12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jne	.L45
	movl	-20(%ebp), %eax
	movl	%eax, -8(%ebp)
.L45:
	addl	$1, -16(%ebp)
.L43:
	movl	R, %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	cmpl	-16(%ebp), %eax
	jg	.L46
	movl	R, %eax
	addl	%eax, -20(%ebp)
.L42:
	movl	-20(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	.L47
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	.L48
.L52:
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	.L49
.L51:
	movl	-20(%ebp), %eax
	cmpl	8(%ebp), %eax
	je	.L50
	movl	-16(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	.L50
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	-16(%ebp), %edx
	addl	%edx, %eax
	movl	arr(,%eax,4), %eax
	cmpl	-4(%ebp), %eax
	jne	.L50
	movl	$0, %eax
	jmp	.L37
.L50:
	addl	$1, -16(%ebp)
.L49:
	movl	R, %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	cmpl	-16(%ebp), %eax
	jg	.L51
	addl	$1, -20(%ebp)
.L48:
	movl	R, %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	cmpl	-20(%ebp), %eax
	jg	.L52
	movl	$1, %eax
.L37:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	check_it, .-check_it
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
