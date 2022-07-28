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
	mov rax, 0
	mov r11, -1	; base length
	call check_base
	dec rdi
	call skip_whitespaces
	dec rdi
	call skip_signs
	dec rdi
	call convert_number
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
	cmp byte [rsi + r11], 9		; '\t'
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

	mov r8b, byte [rsi + r10]
	cmp r8b, r9b
	je error

	jmp check_base_duplicate
check_base_duplicate_ret:
	ret

; Skip starting whitespaces in str
skip_whitespaces:
	inc rdi
	cmp byte [rdi], ' '
	je skip_whitespaces
	cmp byte [rdi], 9	; '\t'
	je skip_whitespaces
	cmp byte [rdi], 10	; '\n'
	je skip_whitespaces
	cmp byte [rdi], 11	; '\v'
	je skip_whitespaces
	cmp byte [rdi], 12	; '\f'
	je skip_whitespaces
	cmp byte [rdi], 13	; '\r'
	je skip_whitespaces
	ret

; Skip signs in str
skip_signs:
	inc rdi
	cmp byte [rdi], '+'
	je skip_signs
	cmp byte [rdi], '-'	; TODO: keep track if number is negative or not
	je skip_signs
	ret

is_char_in_base:
	inc r11
	cmp byte [rsi + r11], 0
	je is_char_in_base_ret
	mov r8b, byte [rsi + r11]
	cmp r8b, r9b
	jne is_char_in_base
	mov r10, 1
is_char_in_base_ret:
	ret

get_base_size:
	inc r9
	cmp byte [rsi + r9], 0
	jne get_base_size
	ret

mul_rax:
	call get_base_size
	cmp r9, 0
	je mul_rax_ret
	mul r9
mul_rax_ret:
	ret

; Convert number until a char is not in base
convert_number:
	inc rdi
	cmp byte [rdi], 0
	je convert_number_ret
	mov r10, 0
	mov r9b, byte [rdi]
	mov r11, -1
	call is_char_in_base
	cmp r10, 0				; char is not in base
	je convert_number_ret
	mov r9, -1				; base size
	call mul_rax
	add rax, r11			; r11 is char index in base
	jmp convert_number
convert_number_ret:
	ret
