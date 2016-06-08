section .text
    global  _ft_memchr

    _ft_memchr:
            xor     rax, rax
            mov     al, sil
            repnz   scasb
            cmp     rcx, 0
            je      _end
            dec     rdi     
            mov     rax, rdi
            ret

    _end:
            mov     rax, 0
            ret

