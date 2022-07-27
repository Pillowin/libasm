; int ft_atoi_base(char *str, char *base);
; RAX ft_atoi_base(   RDI   ,     RSI   );

; RAX: 1st return register
; RDI: used to pass 1st argument to functions
; RSI: used to pass 2nd argument to functions

; R8:  temporary register
; R9:  temporary register
; R10: temporary register
; R11: temporary register

; R8B: lower 8 bits of R8

global _ft_atoi_base

section .text

_ft_atoi_base:
	mov rax, 42
	mov r11, -1	; base length
	call check_base
	ret

error:
	mov rax, 0
	ret

; If base is invalid, returns error
check_base:
	inc r11
	call check_base_char

	mov r10, r11
	mov r9b, byte [rsi + r11]	; store char in base at pos r11
	call check_base_duplicate

	cmp byte [rsi + r11], 0
	jne check_base

	call check_base_length
	ret

; If base contains '+', '-' or any whitespaces, returns error
check_base_char:
	cmp byte [rsi + r11], '+'
	je error
	cmp byte [rsi + r11], '-'
	je error
	cmp byte [rsi + r11], ' '
	je error
	cmp byte [rsi + r11], 9	;	'\t'
	je error
	cmp byte [rsi + r11], 10	; '\n'
	je error
	cmp byte [rsi + r11], 11	; '\v'
	je error
	cmp byte [rsi + r11], 12	; '\f'
	je error
	cmp byte [rsi + r11], 13	; '\r'
	je error
	ret

; If base length <= 1, returns error
check_base_length:
	cmp r11, 1
	jle error
	ret

; If current base char (rsi + r11) is previously used, returns error
check_base_duplicate:
	cmp r11, 0
	je check_base_duplicate_ret

	cmp byte [rsi + r11], 0
	je check_base_duplicate_ret

	dec r10
	cmp r10, 0
	jl check_base_duplicate_ret

	mov r8b, byte [rsi + r10]	; store char in base at pos r10
	cmp r8b, r9b
	je error

	jmp check_base_duplicate
check_base_duplicate_ret:
	ret
