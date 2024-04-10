DATA SEGMENT
    Buffer DB 05H, 06H, 07H, 08H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    XOR DX, DX             ; 清空 DX
    MOV AL, BYTE PTR Buffer; 加载第一个 BCD 码
    ADD DL, AL             ; 将其添加到 DX 的低字节
    MOV AL, BYTE PTR Buffer+1 ; 加载第二个 BCD 码
    SHL DL, 4              ; 将 DX 的低字节左移 4 位
    ADD DL, AL             ; 将第二个 BCD 码添加到 DX 的低字节
    MOV AL, BYTE PTR Buffer+2 ; 加载第三个 BCD 码
    ADD DH, AL             ; 将其添加到 DX 的高字节
    MOV AL, BYTE PTR Buffer+3 ; 加载第四个 BCD 码
    SHL DH, 4              ; 将 DX 的高字节左移 4 位
    ADD DH, AL             ; 将第四个 BCD 码添加到 DX 的高字节

    ; 此时，DX 的内容为 8765H

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START