.model small

.data 
    first dw 1234h, 1234h
    second dw 9999h, 9999h
    result dw 2 dup(0)
    temp dw ?
    msg db "Result: $", 10
    temp1 dw ?
.code
    .startup
    mov si, 0h
    lea dx, msg
    mov ah, 09h
    int 21h

    mov cx, 2h
    clc
    arr:
        mov ax, first[si]
        mov bx, second[si]
        sbb al, bl
        das
        sbb ah, bh
        xchg ah, al
        das
        xchg al, ah
        mov result[si], ax
        inc si
        inc si
    loop arr

    mov cx, 2h
    ;check if the result is negative
    jnc print2
    ;print '-' character
    mov dl, 2dh
    mov ah, 02h
    int 21h
    
    ;10's complement
    mov si, 0h

    compl:
        ;adc result[i], 0
        mov ax, 9999h
        mov bx, result[si]
        sub al, bl
        das
        sub ah, bh
        xchg ah, al
        das
        xchg al, ah
        ; inc ax
        ; daa
        mov result[si], ax
        ;inc result[si]
        inc si
        inc si
    loop compl

    mov si, 0h
    mov cx, 2h
    stc
    add1:
        mov ax, result[si]
        adc al, 0h
        daa
        xchg ah, al
        adc al, 0h
        daa
        xchg ah, al
        mov result[si], ax
        inc si
        inc si
    loop add1
    mov cx, 2h

    print2:
        dec si
        dec si
        mov temp, cx
        mov bx, result[si]
        mov cx, 4
        print: 
            rol bx, 4
            mov dl, bl
            and dl, 0fh
            add dl, 30h
            cmp dl, 39h
            jbe print12
            add dl, 07h
            print12:
                mov ah, 02h
                int 21h
        loop print
        mov cx, temp
    loop print2
    .exit
end