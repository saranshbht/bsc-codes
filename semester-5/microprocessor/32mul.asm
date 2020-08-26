.model small

.data
    first dw 1234h, 5678h
    second dw 5678h, 1234h
    result dw 4 dup(0)
    tempcount dw ?
    msg db "Result: $", 10

.code
    .startup
    lea dx, msg
    mov ah, 09h
    int 21h

    mov ax, first[0h]
    mul second[0h]

    mov result[2h], dx
    mov result[0h], ax

    mov ax, first[0h]
    mul second[2h]  
    mov result[4h], dx
    add result[2h], ax
    adc result[4h], 0h

    mov ax, first[2h]
    mul second[0h]
    add result[2h], ax
    adc result[4h], dx
    adc result[6h], 0h

    mov ax, first[2h]
    mul second[2h]
    add result[4h], ax
    adc result[6h], dx


    mov cx, 4
    mov si, 6h
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

