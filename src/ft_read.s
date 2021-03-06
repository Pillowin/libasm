; ssize_t ft_read(int fildes, void *buf, size_t nbyte);
;   RAX   ft_read(    RDI   ,    RSI   ,      RDX    );

; RBP: callee-saved register; optionally used as frame pointer
; RSP: stack pointer

; RAX: 1st return register
; RDI: used to pass 1st argument to functions
; RSI: used to pass 2nd argument to functions
; RDX: used to pass 3rd argument to functions

%define MACH_SYSCALL(nb)	0x02000000 | nb
%define READ				3

section .text
	global	_ft_read
	extern	___error

_ft_read:
	push rbp
	mov rbp, rsp
	and rsp, 0xFFFFFFFFFFFFFFF0

	mov rax, MACH_SYSCALL(READ)
	syscall
	jc set_errno

	pop rbp
	ret

set_errno:
	push rax
	sub rsp, 8
	call ___error
	add rsp, 8
	pop qword [rax]
	mov rax, -1

	mov rsp, rbp
	pop rbp
	ret
