DATA SEGMENT
    A DW 9856H,0A680H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    MOV AX, WORD PTR A+2   ; ����λ�ּ��ص� AX
    OR AX, AX              ; ������λ
    JNS NoNeg              ; ���������������ת�� NoNeg

    ; ������Ǹ�����ȡ������ 1
    NOT WORD PTR A         ; ȡ����λ��
    NOT AX                 ; ȡ����λ��
    ADD WORD PTR A, 1      ; ��λ�ּ� 1
    ADC AX, 0              ; ��λ�ּӽ�λ
    MOV WORD PTR A+2, AX   ; �������ظ�λ��

NoNeg:
    ; ��ʱ��A �� A+2 �е�ֵ���Ǿ���ֵ

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START