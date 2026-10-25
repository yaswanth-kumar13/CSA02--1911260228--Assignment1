	.file	"Task08.c"
	.text
	.globl	calculate_bill
	.def	calculate_bill;	.scl	2;	.type	32;	.endef
	.seh_proc	calculate_bill
calculate_bill:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$100, 16(%rbp)
	jle	.L2
	movl	16(%rbp), %eax
	subl	$100, %eax
	addl	%eax, %eax
	movl	%eax, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	addl	$50, %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "TASK 08 - COMPILATION PROCESS\0"
.LC1:
	.ascii "-----------------------------\0"
.LC2:
	.ascii "Units consumed: %d\12\0"
.LC3:
	.ascii "Fixed charge: Rs. %d\12\0"
	.align 8
.LC4:
	.ascii "Total electricity bill: Rs. %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$150, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	calculate_bill
	movl	%eax, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	-4(%rbp), %eax
	leaq	.LC2(%rip), %rcx
	movl	%eax, %edx
	call	printf
	leaq	.LC3(%rip), %rax
	movl	$50, %edx
	movq	%rax, %rcx
	call	printf
	movl	-8(%rbp), %eax
	leaq	.LC4(%rip), %rcx
	movl	%eax, %edx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev4, Built by MSYS2 project) 16.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
