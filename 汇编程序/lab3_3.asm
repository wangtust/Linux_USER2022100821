; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here
MOV AX,53
MOV BX,-49
SHL AX,1
SHL BX,1
MOV AX, 53   ; 将AX寄存器的值设置为53
MOV BX, 0FFCFH ; 将BX寄存器的值设置为-49的二进制补码形式
SHL AX, 1    ; 将AX寄存器的值左移一位，相当于乘以2
SHL BX, 1    ; 将BX寄存器的值左移一位，相当于乘以2
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
