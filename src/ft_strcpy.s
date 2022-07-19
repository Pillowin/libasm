; char * ft_strcpy(char * dst, const char * src);
;  RAX   ft_strcpy(    RDI   ,        RSI      );

; RAX: 1st return register
; RDI: used to pass 1st argument to functions
; RSI: used to pass 2nd argument to functions

; RBP: callee-saved register; optionally used as frame pointer
; RSP: stack pointer

; RCX: rep counter that decrements and stop rep if 0

global _ft_strcpy
extern _ft_strlen

_ft_strcpy:
	push rbp
	mov rbp, rsp
	and rsp, 0xFFFFFFFFFFFFFFF0

	push rdi
	push rsi

	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax

	pop rsi
	pop rdi

	cld
	rep movsb

	sub rdi, rax
	mov rax, rdi

	mov rsp, rbp
	pop rbp
	ret

