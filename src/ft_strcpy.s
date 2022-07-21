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

section .text

_ft_strcpy:
	push rdi
	push rsi

	mov rdi, rsi
	sub rsp, 8
	call _ft_strlen
	add rsp, 8
	mov rcx, rax

	pop rsi
	pop rdi

	cld
	rep movsb

	sub rdi, rax
	mov rax, rdi
	ret

