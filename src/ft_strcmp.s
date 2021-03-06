; int ft_strcmp(const char* s1, const char* s2);
; RAX ft_strcmp(      RDI     ,       RSI     );

; RAX: 1st return register
; RDI: used to pass 1st argument to functions
; RSI: used to pass 2nd argument to functions

; RBP: callee-saved register; optionally used as frame pointer
; RSP: stack pointer

; XMM0:	str to compare => s2
; RCX:	Index where mismatched char was found
; ZFlag: Set if a '\0' was found
; CFlag: Set if a char mismatched

; Little Endian
; IMM8[6]	= 0b	The bit index number of the LSB of IntRes2.
; IMM8[5:4]	= 01b	Invert each bit of IntRes1 and set to IntRes2.
; IMM8[3:2]	= 10b	Test if the input strings are equal.
; IMM8[1:0]	= 00b	unsigned BYTE
IMM8 EQU 0011000b

global _ft_strcmp

section .text

_ft_strcmp:
	mov rax, rdi	; Arg1: copy s1(pointer to string) to rax
	sub rax, rsi	; Offset between s1 and s2 to use only 1 index
	sub rsi, 16		; Avoid extra jump in main loop

ft_strcmp_loop:
	add rsi, 16
	movdqu xmm0, [rsi]
	pcmpistri xmm0, [rax + rsi], IMM8
	ja ft_strcmp_loop		; No '\0' AND No mismatching char (CF=0 and ZF=0)
	jc ft_strcmp_missmatch	; Mismatched char (CF=1)
	xor rax, rax			; (s1 == s2) => ret = 0
	ret

ft_strcmp_missmatch:
	add rax, rsi				; Set offset into s1 to match s2
	movzx rax, byte[rax + rcx]	; Advance at mismatching char and fill with '\0'
	movzx rsi, byte[rsi + rcx]	; to sub only 1 char
	sub rax, rsi				; if (s1 < s2) {rax <0} else {rax >0}
	ret
