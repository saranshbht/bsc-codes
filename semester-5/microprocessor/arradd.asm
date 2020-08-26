.model small

.data
    A db 54h, 10h, 3h, 5h, 6h, 27h
    B db 0b9h, 0f7h, 2h, 4h, 0h, 15h
    msg db "Resultant array: $", 10
    tempcx dw ?
.code
    .startup
    lea dx, msg
    mov ah, 09h
    int 21h

    mov si, 0h
    mov cx, 6h
    output:
        mov bl, A[si]
        add bl, B[si]

        jnc nocarry
        mov dl, 31h
        mov ah, 02h
        int 21h
        
        nocarry:
            mov tempcx, cx
            mov cx, 2h
            bitByBit:
                rol bl, 4h
                mov dl, bl
                and dl, 0fh
                cmp dl, 9
                jbe lessThan10
                add dl, 07h
                lessThan10:
                    add dl, 30h 
                    mov ah, 02h
                    int 21h
            loop bitByBit

            mov dl, 20h
            mov ah, 02h
            int 21h
            
            inc si
            mov cx, tempcx
    loop output
    .exit
end