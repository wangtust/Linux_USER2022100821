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
    XOR DX, DX   ; ��� DX  
MOV AL,10H
MOV BL,20H
MOV CL,30H
MOV DL,40H
MOV AH, 0    ; ��� AH
MOV BH, 0    ; ��� BH
MOV CH, 0    ; ��� CH
MOV DH, 0    ; ��� DH

ADD AX, BX   ; �� AL �� BL ��ӣ�����洢�� AX ��
ADD DX, CX   ; ��DX,CX��ӽ���� DX ��
ADD DX, AX   ; ��DX,AX��� ����ŵ�DX��
   
            
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
