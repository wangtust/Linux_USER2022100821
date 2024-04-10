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
    mov bl, 255 ; 将256存入BL寄存器
    mov cl, 8 ; 将8存入CL寄存器
    mov ah, 0 ; 将AH寄存器清零，因为DIV指令会使用AX寄存器
    mov al, bl ; 将BL寄存器的值移动到AL寄存器
    div cl ; 将AX寄存器中的值除以CL寄存器中的值，结果存入AL寄存器，余数存入AH寄存器
    add al, al ; 将AL寄存器中的值乘以2
    mov dx, ax ; 将AX寄存器中的值存入DX寄存器

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
