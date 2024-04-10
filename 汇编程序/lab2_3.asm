DATA SEGMENT
    A DW 9856H,0A680H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    MOV AX, WORD PTR A+2   ; 将高位字加载到 AX
    OR AX, AX              ; 检查符号位
    JNS NoNeg              ; 如果数是正数，跳转到 NoNeg

    ; 如果数是负数，取反并加 1
    NOT WORD PTR A         ; 取反低位字
    NOT AX                 ; 取反高位字
    ADD WORD PTR A, 1      ; 低位字加 1
    ADC AX, 0              ; 高位字加进位
    MOV WORD PTR A+2, AX   ; 将结果存回高位字

NoNeg:
    ; 此时，A 和 A+2 中的值就是绝对值

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START