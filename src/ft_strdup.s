; char * ft_strdup(const char *s1);
;  RAX   ft_strcpy(      RDI     );

; RAX: 1st return register
; RDI: used to pass 1st argument to functions

; RBP: callee-saved register; optionally used as frame pointer
; RSP: stack pointer

; RCX: lenght of s1

global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
	push rdi			; save s1
	call _ft_strlen
	mov rcx, rax		; store s1 len + 1 in rcx and stack
	inc rcx

	mov rdi, rcx		; allocate rcx bytes
	push rcx
	sub rsp, 8
	call _malloc
	add rsp, 8
	pop rcx
	pop rsi
	cmp rax, 0
	je exit_ft_strdup

	cld
	mov rdi, rax
	rep movsb			; copy rcx bytes from rsi to rdi

exit_ft_strdup:
	ret
