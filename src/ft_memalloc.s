section .text
    global  _ft_memalloc
    extern  _malloc
    extern  _ft_bzero

_ft_memalloc:
    push        rdi
    call        _malloc
    cmp         rax, 0
    jz          _end
    mov         rdi, rax
    pop         rsi
    call        _ft_bzero

_end:
    ret
