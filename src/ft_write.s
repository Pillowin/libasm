; ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
;   RAX   ft_write(    RDI   ,       RSI      ,      RDX    );

; RBP: callee-saved register; optionally used as frame pointer
; RSP: stack pointer

; RAX: 1st return register
; RDI: used to pass 1st argument to functions
; RSI: used to pass 2nd argument to functions
; RDX: used to pass 3rd argument to functions

%define MACH_SYSCALL(nb)	0x02000000 | nb
%define WRITE				4

section	.text
	global	_ft_write

_ft_write:
	push	rbp
	mov		rbp, rsp

	mov		rax, MACH_SYSCALL(WRITE)
	syscall
	;TODO: check errors

	mov		rsp, rbp
	pop		rbp
	ret
