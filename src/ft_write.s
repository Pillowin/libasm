          section   .text

          global    _ft_write				; ssize_t write(int fildes, const void *buf, size_t nbyte);
		                                    ;   RAX   write(		  ,                ,             );

											; RAX -> Integer return values (similar to x86) are returned in RAX if 64 bits or less.
_ft_write:
          mov       rax, 0x02000004         ; system call for write
          syscall                           ; invoke operating system to do the write
