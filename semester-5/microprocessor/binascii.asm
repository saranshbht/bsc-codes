.model small

.data
    msg db "Enter a binary number(8-bit): $"
    msg1 db 10, "ASCII character corresponding to the binary number: $"
.code
    .startup
        lea dx, msg
        mov ah, 09h
        int 21h

        mov cx, 8
        mov bl, 0

        input:
            shl bl, 1
            mov ah, 01h
            int 21h
            sub al, 30h
            add bl, al
        loop input

        lea dx, msg1
        mov ah, 09h
        int 21h
        
        mov dl, bl
        mov ah, 02h
        int 21h
    .exit
end