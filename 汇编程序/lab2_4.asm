DATA SEGMENT
    Buffer DB 05H, 06H, 07H, 08H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    XOR DX, DX             ; ��� DX
    MOV AL, BYTE PTR Buffer; ���ص�һ�� BCD ��
    ADD DL, AL             ; ������ӵ� DX �ĵ��ֽ�
    MOV AL, BYTE PTR Buffer+1 ; ���صڶ��� BCD ��
    SHL DL, 4              ; �� DX �ĵ��ֽ����� 4 λ
    ADD DL, AL             ; ���ڶ��� BCD ����ӵ� DX �ĵ��ֽ�
    MOV AL, BYTE PTR Buffer+2 ; ���ص����� BCD ��
    ADD DH, AL             ; ������ӵ� DX �ĸ��ֽ�
    MOV AL, BYTE PTR Buffer+3 ; ���ص��ĸ� BCD ��
    SHL DH, 4              ; �� DX �ĸ��ֽ����� 4 λ
    ADD DH, AL             ; �����ĸ� BCD ����ӵ� DX �ĸ��ֽ�

    ; ��ʱ��DX ������Ϊ 8765H

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START