data segment
    X dw 16 ; �������X����ʼ��Ϊ16
    Y dw 2  ; �������Y����ʼ��Ϊ2
    W dw 8  ; �������W����ʼ��Ϊ8
    R dw 32 ; �������R����ʼ��Ϊ32
    Z dw ?  ; �������Z�������г�ʼ��
    pkey db "press any key...$" ; ����һ���ַ���
ends

stack segment
    dw   128  dup(0) ; ����һ��128�ֽڵ�ջ������Ԫ�س�ʼ��Ϊ0
ends

code segment
start:
; set segment registers:
    mov ax, data ; �����ݶε�ַ���ص�ax�Ĵ���
    mov ds, ax   ; ��ax�Ĵ�����ֵ����Ϊ���ݶμĴ�����ֵ
    mov es, ax   ; ��ax�Ĵ�����ֵ����Ϊ���ӶμĴ�����ֵ

    ; Z��W-(X+6)-(R+9)
    mov ax, [X]  ; ��X��ֵ���ص�ax�Ĵ���
    add ax, 6    ; ��ax�Ĵ�����ֵ��6
    mov bx, [R]  ; ��R��ֵ���ص�bx�Ĵ���
    add bx, 9    ; ��bx�Ĵ�����ֵ��9
    add ax, bx   ; ��ax�Ĵ�����ֵ��bx�Ĵ�����ֵ���
    mov bx, [W]  ; ��W��ֵ���ص�bx�Ĵ���
    sub bx, ax   ; ��bx�Ĵ�����ֵ��ȥax�Ĵ�����ֵ
    mov [Z], bx  ; ��bx�Ĵ�����ֵ�洢��Z

    ; Z��(W*X)/(Y+6)��R������
    mov ax, [W]  ; ��W��ֵ���ص�ax�Ĵ���
    mov bx, [X]  ; ��X��ֵ���ص�bx�Ĵ���
    imul bx      ; ��ax�Ĵ�����ֵ��bx�Ĵ�����ֵ��ˣ�����洢��DX:AX��
    mov bx, [Y]  ; ��Y��ֵ���ص�bx�Ĵ���
    add bx, 6    ; ��bx�Ĵ�����ֵ��6
    idiv bx      ; ��DX:AX��ֵ����bx�Ĵ�����ֵ���̴洢��ax�Ĵ����������洢��dx�Ĵ���
    mov [Z], ax  ; ��ax�Ĵ�����ֵ�洢��Z
    mov [R], dx  ; ��dx�Ĵ�����ֵ�洢��R
            
    lea dx, pkey ; ���ַ���pkey�ĵ�ַ���ص�dx�Ĵ���
    mov ah, 9    ; ����ah�Ĵ�����ֵΪ9����ӦDOS�Ĵ�ӡ�ַ�������
    int 21h      ; ����DOS�ж�
    
    ; wait for any key....    
    mov ah, 1    ; ����ah�Ĵ�����ֵΪ1����ӦDOS�ļ������빦��
    int 21h      ; ����DOS�ж�
    
    mov ax, 4c00h ; ����ax�Ĵ�����ֵΪ4c00h����ӦDOS���˳�������
    int 21h      ; ����DOS�ж�
ends

end start ; ���ó�����ڵ�Ϊstart����ֹͣ���