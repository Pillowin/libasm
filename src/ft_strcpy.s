; char * ft_strcpy(char * dst, const char * src);
;  rax   ft_strcpy(    rdi   ,        rsi      );

; rax: 1st return register
; rdi: used to pass 1st argument to functions
; rsi: used to pass 2nd argument to functions

; rbp: callee-saved register; optionally used as frame pointer
; rsp: stack pointer

; rcx: rep counter that decrements and stop rep if 0

global _ft_strcpy
extern _ft_strlen

_ft_strcpy:
	push rbp
	mov rbp, rsp

	push rdi
	push rsi
	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax
	pop rsi
	pop rdi

	cld
	rep movsb
	mov rax, rsi

	pop rbp
	ret

