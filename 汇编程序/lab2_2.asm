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
MOV AX,1H
MOV DI,1H
MOV SI,2H
MOV BP,3H
MOV BX, AX   ; 将 AX 的值复制到 BX
SUB BX, DI   ; 从 BX 中减去 DI 的值
SUB BX, SI   ; 从 BX 中减去 SI 的值
SUB BX, BP   ; 从 BX 中减去 BP 的值
            
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
