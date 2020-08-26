.model small

.data
    first db 0ffh
    second db 0eeh
    msg db "Result: $", 10

.code
    .startup
    lea dx, msg
    mov ah, 09h
    int 21h

    mov al, first
    mul second

    mov cx, 4
    mov bx, ax
    print:
        rol bx, 4
        mov dl, bl
        and dl, 0fh
        add dl, 30h
        cmp dl, 39h
        jbe print1
        add dl, 07h
        print1:
            mov ah, 02h
            int 21h
    loop print

    .exit
end