; size_t ft_strlen(const char *s);
;  rax   ft_strlen(     rdi     );

; rax: 1st return register
; rdi: used to pass 1st argument to functions

; rbp: callee-saved register; optionally used as frame pointer
; rsp: stack pointer

; rcx: rep counter that decrements and stop rep if 0

section .text
	global	_ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp

	cld
	xor		rax, rax
	mov		rcx, -1		; max register value to not use this stop condition
	repne	scasb
	mov		rax, -2		; add back max register value -1 for '\0'
	sub		rax, rcx

	pop		rbp
	ret
