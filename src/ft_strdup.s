; char * ft_strdup(const char *s1);
;  rax   ft_strcpy(      rdi     );

; rax: 1st return register
; rdi: used to pass 1st argument to functions

; rbp: callee-saved register; optionally used as frame pointer
; rsp: stack pointer

; rcx: lenght of s1
; r12: callee saved register
; r13: callee saved register

global _ft_strdup
extern _ft_strlen
extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp

	mov r12, rdi		; save s1
	call _ft_strlen
	mov rcx, rax		; store s1 len + 1 in rcx and r13
	inc rcx
	mov r13, rcx

	mov rdi, rcx		; allocate rcx bytes
	call _malloc
	cmp rax, 0
	je exit_ft_strdup

	cld
	mov rdi, rax
	mov rsi, r12
	mov rcx, r13
	rep movsb			; copy rcx bytes from rsi to rdi

exit_ft_strdup:
	pop rbp
	ret
