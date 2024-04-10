data segment
    ARRAY dw 23, 36, 2, 100, 32000, 54, 0
    ZERO dw ?
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

    ; (1) �����BX�������ARRAY�ĳ�ʼ��ַ�����дָ�ARRAY�е�����0���͸�ZERO��Ԫ��
    mov bx, OFFSET ARRAY ; ������ARRAY�ĳ�ʼ��ַ��ŵ�BX�Ĵ���
    mov ax, [bx+12] ; ���������еĵ�7��Ԫ�أ�ÿ��Ԫ��Ϊ2�ֽڣ�����ƫ����Ϊ6*2=12��
    mov [ZERO], ax ; ��AX�Ĵ�����ֵ�洢��ZERO��Ԫ

    ; (2) �����BX���ARRAY������0�������е�λ���������дָ�����0���͸�ZERO��Ԫ��
    mov bx, 12 ; ��BX�Ĵ�����ֵ����Ϊ0Ԫ���������е�λ����
    mov ax, [ARRAY+bx] ; ���������еĵ�7��Ԫ��
    mov [ZERO], ax ; ��AX�Ĵ�����ֵ�洢��ZERO��Ԫ
            
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.