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
MOV AX, 53   ; ��AX�Ĵ�����ֵ����Ϊ53
MOV BX, 0FFCFH ; ��BX�Ĵ�����ֵ����Ϊ-49�Ķ����Ʋ�����ʽ
SHL AX, 1    ; ��AX�Ĵ�����ֵ����һλ���൱�ڳ���2
SHL BX, 1    ; ��BX�Ĵ�����ֵ����һλ���൱�ڳ���2
            
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
