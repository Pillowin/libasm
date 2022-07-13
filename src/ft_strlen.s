; size_t ft_strlen(const char *s);
;  rax   ft_strlen(     rdi     );

; rax: 1st return register
; rdi: used to pass 1st argument to functions

; rbp: callee-saved register; optionally used as frame pointer
; rsp: stack pointer

; xmm0: byte to find => '\0'
; rcx: Index where '\0' was found
; ZFlag: Set if any byte/word of xmm2/mem128 is null, reset otherwise

; Little Endian
; IMM8[6]	= 0b	The bit index number of the LSB of IntRes2.
; IMM8[5:4]	= 00b	Copy IntRes1 to IntRes2.
; IMM8[3:2]	= 10b	Test if the input strings are equal.
; IMM8[1:0]	= 00b	unsigned BYTE
IMM8 EQU 0001000b

global _ft_strlen

section .text

_ft_strlen:
	push rbp
	mov rbp, rsp

	pxor xmm0, xmm0	; 0 for '\0'
	mov rax, -16	; will start at index 0

ft_strlen_loop:
	add rax, 16							; increment 16 by 16
	pcmpistri xmm0, [rdi + rax], IMM8
	jnz ft_strlen_loop					; jump if no '\0' found
	add rax, rcx						; add offset where '\0' was found

	pop rbp
	ret
