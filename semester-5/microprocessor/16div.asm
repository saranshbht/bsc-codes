.model small

.data
    first dw 256
    second db 128
    tempah db ?
    tempal db ?
    msg1 db "Quotient: $"
    msg2 db 10, "Remainder: $"

.code
    .startup

    mov ax, first
    div second
    mov tempah, ah
    mov tempal, al

    lea dx, msg1
    mov ah, 09h
    int 21h
    mov cx, 2
    mov bl, tempal
    print1:
        rol bl, 4
        mov dl, bl
        and dl, 0fh
        add dl, 30h
        cmp dl, 39h
        jbe print11
        add dl, 07h
        print11:
            mov ah, 02h
            int 21h
    loop print1

    lea dx, msg2
    mov ah, 09h
    int 21h

    mov cx, 2
    mov bl, tempah
    print2:
        rol bl, 4
        mov dl, bl
        and dl, 0fh
        add dl, 30h
        cmp dl, 39h
        jbe print21
        add dl, 07h
        print21:
            mov ah, 02h
            int 21h
    loop print2

    .exit
end