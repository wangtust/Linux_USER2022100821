	.file	"memory.c"
	.text
	.globl	glob1
	.data
	.align 4
	.type	glob1, @object
	.size	glob1, 4
glob1:
	.long	5
	.globl	glob2
	.align 4
	.type	glob2, @object
	.size	glob2, 4
glob2:
	.long	3
	.comm	arr,10,8
	.section	.rodata
.LC0:
	.string	"  sum: %p , value: %d\n"
.LC1:
	.string	"    a: %p , value: %d\n"
.LC2:
	.string	"    b: %p , value: %d\n\n"
	.text
	.globl	add
	.type	add, @function
add:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %edx
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %edx
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-24(%rbp), %edx
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	add, .-add
	.section	.rodata
.LC3:
	.string	"  env: %p , value: %s\n\n"
.LC4:
	.string	" argc: %p , value: %d\n\n"
.LC5:
	.string	"  sum: %p , value: %d\n\n"
.LC6:
	.string	"    p: %p , value: %d\n\n"
.LC7:
	.string	"  arr: %p , value: %d\n"
.LC8:
	.string	"glob2: %p , value: %d\n"
.LC9:
	.string	"glob1: %p , value: %d\n\n"
.LC10:
	.string	" main: %p\n"
.LC11:
	.string	"  add: %p\n\n"
.LC12:
	.string	"sum=%d\n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	environ(%rip), %rax
	movq	(%rax), %rdx
	movq	environ(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-36(%rbp), %edx
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %edx
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	glob2(%rip), %edx
	movl	glob1(%rip), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	add
	movl	%eax, -20(%rbp)
	movl	$10, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movb	$32, (%rax)
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movzbl	arr(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	arr(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	glob2(%rip), %eax
	movl	%eax, %edx
	leaq	glob2(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	glob1(%rip), %eax
	movl	%eax, %edx
	leaq	glob1(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	main(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	add(%rip), %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
