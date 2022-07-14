; char * ft_strcpy(char * dst, const char * src);
;  rax   ft_strcpy(    rdi   ,        rsi      );

; rax: 1st return register
; rdi: used to pass 1st argument to functions
; rsi: used to pass 2nd argument to functions

; rbp: callee-saved register; optionally used as frame pointer
; rsp: stack pointer

; rcx: rep counter that decrements and stop rep if 0
; r12: callee saved register
; r13: callee saved register

global _ft_strcpy
extern _ft_strlen

_ft_strcpy:
	push rbp
	mov rbp, rsp

	mov r12, rdi
	mov r13, rsi

	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax

	mov rdi, r12
	mov rsi, r13

	cld
	rep movsb

	sub rdi, rax
	mov rax, rdi

	pop rbp
	ret

