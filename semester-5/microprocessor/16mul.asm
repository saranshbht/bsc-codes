.model small

.data
first dw 1223h
second dw 1242h
result dw 2 dup(0)
tempcount dw ?
msg db "Result: $", 10

.code
    .startup
    lea dx, msg
    mov ah, 09h
    int 21h

    mov ax, first
    mul second
    mov result[0h], ax
    mov result[2h], dx
    
    mov si, 2h
    mov cx, 2
    print:
        mov bx, result[si]
        mov tempcount, cx
        mov cx, 4
        print1: 
            rol bx, 4
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
        dec si
        dec si
        mov cx, tempcount
    loop print

    .exit
end