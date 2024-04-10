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
    mov bl, 255 ; ��256����BL�Ĵ���
    mov cl, 8 ; ��8����CL�Ĵ���
    mov ah, 0 ; ��AH�Ĵ������㣬��ΪDIVָ���ʹ��AX�Ĵ���
    mov al, bl ; ��BL�Ĵ�����ֵ�ƶ���AL�Ĵ���
    div cl ; ��AX�Ĵ����е�ֵ����CL�Ĵ����е�ֵ���������AL�Ĵ�������������AH�Ĵ���
    add al, al ; ��AL�Ĵ����е�ֵ����2
    mov dx, ax ; ��AX�Ĵ����е�ֵ����DX�Ĵ���

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
