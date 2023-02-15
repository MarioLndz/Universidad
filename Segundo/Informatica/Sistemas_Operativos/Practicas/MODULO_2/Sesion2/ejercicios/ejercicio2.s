	.file	"ejercicio2.c"
	.text
	.section	.rodata
.LC0:
	.string	"Error"
.LC1:
	.string	"BIEN"
.LC2:
	.string	"%s/%s"
	.align 8
.LC3:
	.string	"ERROR AL INTENTAR ACCEDER A ATRIBUTOS"
.LC4:
	.string	"%s \t:  %o\t"
.LC5:
	.string	"%o \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$704, %rsp
	movl	%edi, -692(%rbp)
	movq	%rsi, -704(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$3, -692(%rbp)
	je	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L4
.L2:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-704(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -672(%rbp)
	movq	-672(%rbp), %rax
	movq	%rax, %rdi
	call	opendir@PLT
	movq	%rax, -680(%rbp)
	movq	-704(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movl	$8, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	strtol@PLT
	movl	%eax, -684(%rbp)
	jmp	.L4
.L7:
	movq	-664(%rbp), %rax
	leaq	19(%rax), %rcx
	movq	-672(%rbp), %rdx
	leaq	-512(%rbp), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	leaq	-656(%rbp), %rdx
	leaq	-512(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	stat@PLT
	testl	%eax, %eax
	jns	.L5
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$-1, %edi
	call	exit@PLT
.L5:
	movl	-632(%rbp), %eax
	andl	$61440, %eax
	cmpl	$32768, %eax
	jne	.L4
	movl	-632(%rbp), %eax
	movq	-664(%rbp), %rdx
	leaq	19(%rdx), %rcx
	movl	%eax, %edx
	movq	%rcx, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-684(%rbp), %edx
	leaq	-512(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	chmod@PLT
	movl	-684(%rbp), %edx
	leaq	-512(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	chmod@PLT
	testl	%eax, %eax
	jns	.L6
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L4
.L6:
	leaq	-656(%rbp), %rdx
	leaq	-512(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	stat@PLT
	movl	-632(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	movq	-680(%rbp), %rax
	movq	%rax, %rdi
	call	readdir@PLT
	movq	%rax, -664(%rbp)
	cmpq	$0, -664(%rbp)
	jne	.L7
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
