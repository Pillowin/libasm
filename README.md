# libasm
The aim of this project is to get familiar with assembly language.

## References
- [wikipedia x86-64 calling conventions](https://en.wikipedia.org/wiki/X86_calling_conventions#x86-64_calling_conventions)
- [System V AMD64 ABI](https://gitlab.com/x86-psABIs/x86-64-ABI)
- [macos syscalls](https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master)
- [x64 cheatsheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
- [optimize](https://agner.org/optimize/)
- [godbolt](https://godbolt.org/)

### ft_strlen
- [CLD](https://faydoc.tripod.com/cpu/cld.htm)
- [SCAS](https://faydoc.tripod.com/cpu/scas.htm)
- [REPNE](https://faydoc.tripod.com/cpu/repne.htm)
- [PCMPISTRI](https://www.officedaytime.com/simd512e/simdimg/str.php?f=pcmpistri)
- [is it safe to tead past the end](https://stackoverflow.com/questions/37800739/is-it-safe-to-read-past-the-end-of-a-buffer-within-the-same-page-on-x86-and-x64)
