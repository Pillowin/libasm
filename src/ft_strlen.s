; size_t strlen(const char *s);
;  rax   strlen(     rdi     );

; rbp: callee-saved register; optionally used as frame pointer
; rsp: stack pointer

; rax: 1st return register
; rdi: used to pass 1st argument to functions


          global    _ft_strlen

          section   .text

_ft_strlen:
          push      rbp                     ; save previous frame pointer
          mov       rbp, rsp                ; use current stack pointer as frame pointer

		  mov       rax, 1

          pop       rbp                     ; restore previous frame pointer
          ret
