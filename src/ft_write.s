; ssize_t write(int fildes, const void *buf, size_t nbyte);
;   RAX   write(    RDI   ,       RSI      ,      RDX    );

; RBP: callee-saved register; optionally used as frame pointer
; RSP: stack pointer

; RAX: 1st return register
; RDI: used to pass 1st argument to functions
; RSI: used to pass 2nd argument to functions
; RDX: used to pass 3rd argument to functions


          global    _ft_write

          section   .text

_ft_write:
          push      rbp                     ; - equivalent to ENTER instruction but faster
          mov       rbp, rsp                ; |

          mov       rax, 0x02000004         ; system call for write
          syscall                           ; invoke operating system to do the write
		  ;TODO: check errors

          mov       rsp, rbp                ; - equivalent to LEAVE instruction but faster
          pop       rbp                     ; |
          ret
