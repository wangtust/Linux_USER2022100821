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
    XOR DX, DX   ; 清空 DX  
MOV AL,10H
MOV BL,20H
MOV CL,30H
MOV DL,40H
MOV AH, 0    ; 清除 AH
MOV BH, 0    ; 清除 BH
MOV CH, 0    ; 清除 CH
MOV DH, 0    ; 清除 DH

ADD AX, BX   ; 将 AL 和 BL 相加，结果存储在 AX 中
ADD DX, CX   ; 将DX,CX相加结果添到 DX 中
ADD DX, AX   ; 将DX,AX相加 结果放到DX中
   
            
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
