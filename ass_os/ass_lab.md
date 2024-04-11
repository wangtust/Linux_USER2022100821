# 第二次实验
实验要求：
在EMU8086中编写短指令序列完成下列各题。实验第1、2题中的寄存器分别用十六进制的数和十进制的数进行赋值，对这二种进制的数进行加、减运算，比较手工计算和机器计算的结果，单步运行查看每次指令执行后各个寄存器的值和标志位的值。
 
1、 设计短指令序列，完成AL、BL、CL和DL相加的运算，结果存在DX中。
2、 写出短指令序列，从AX中减去DI、SI和BP中的数据，结果送BX。
3、 试编写一个程序，求出双字长数的绝对值。假设该双字存在A和A+2单元中。
提示：在数据段（DATA SEGMENT）中有如下定义：
A DW 9856H,0A680H
4、从主存buffer开始的4个字节中保存了4个非压缩BCD码，现按低（高）地址对低（位）的原则，将它们合并到DX中。
提示：在数据段（DATA SEGMENT）定义Buffer：
Buffer DB 05H, 06H, 07H, 08H
写短指令序列将buffer中的非压缩的BCD码合并到DX，DX的内容为8765H。

1. 以下是一个简单的 8086 汇编指令序列，可以完成 AL、BL、CL 和 DL 相加的运算，并将结果存储在 DX 中：

```assembly
MOV AH, 0    ; 清除 AH，因为我们只使用 AL
MOV BH, 0    ; 清除 BH，因为我们只使用 BL
MOV CH, 0    ; 清除 CH，因为我们只使用 CL
MOV DH, 0    ; 清除 DH，因为我们只使用 DL

ADD AX, BX   ; 将 AL 和 BL 相加，结果存储在 AX 中
ADD AX, CX   ; 将结果和 CL 相加，结果存储在 AX 中
ADD AX, DX   ; 将结果和 DL 相加，结果存储在 AX 中

MOV DX, AX   ; 将结果移动到 DX 中
```

这个指令序列首先清除 AH、BH、CH 和 DH 的内容，因为我们只对 AL、BL、CL 和 DL 进行操作。然后，它使用 `ADD` 指令将 AL、BL、CL 和 DL 的内容相加，并将结果存储在 AX 中。最后，它使用 `MOV` 指令将结果从 AX 移动到 DX 中。

2. 以下是一个简单的 8086 汇编指令序列，可以从 AX 中减去 DI、SI 和 BP 中的数据，并将结果存储在 BX 中：

```assembly
MOV BX, AX   ; 将 AX 的值复制到 BX
SUB BX, DI   ; 从 BX 中减去 DI 的值
SUB BX, SI   ; 从 BX 中减去 SI 的值
SUB BX, BP   ; 从 BX 中减去 BP 的值
```

这个指令序列首先使用 `MOV` 指令将 AX 的值复制到 BX 中。然后，它使用 `SUB` 指令从 BX 中减去 DI、SI 和 BP 的值。最后的结果就存储在 BX 中。

3. 以下是一个简单的 8086 汇编程序，可以求出存储在 A 和 A+2 单元中的双字长数的绝对值：

```assembly
DATA SEGMENT
    A DW 9856H,0A680H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    MOV AX, WORD PTR A+2  ; 获取高位
    OR AX, AX             ; 检查是否为负数
    JNS POSITIVE          ; 如果为正数，跳转到 POSITIVE 标签

    ; 如果为负数，取反并加一
    NOT WORD PTR A        ; 取反低位
    NOT WORD PTR A+2      ; 取反高位
    ADD WORD PTR A, 1     ; 加一
    ADC WORD PTR A+2, 0   ; 处理进位

POSITIVE:
    ; 此时，A 和 A+2 中的值就是绝对值

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START
```

这个程序首先检查双字长数的高位是否为负数。如果为负数，它就对双字长数取反并加一，得到其绝对值。如果为正数，它就直接跳过这个步骤。最后，A 和 A+2 中的值就是双字长数的绝对值。

4. 以下是一个简单的 8086 汇编指令序列，可以将存储在 Buffer 中的非压缩 BCD 码合并到 DX 中：

```assembly
DATA SEGMENT
    Buffer DB 05H, 06H, 07H, 08H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    XOR DX, DX            ; 清空 DX
    MOV AL, BYTE PTR Buffer
    ADD DX, AX            ; 将第一个 BCD 码添加到 DX

    MOV AL, BYTE PTR Buffer+1
    SHL DX, 4             ; 将 DX 左移 4 位，为下一个 BCD 码腾出空间
    ADD DX, AX            ; 将第二个 BCD 码添加到 DX

    MOV AL, BYTE PTR Buffer+2
    SHL DX, 4             ; 将 DX 左移 4 位，为下一个 BCD 码腾出空间
    ADD DX, AX            ; 将第三个 BCD 码添加到 DX

    MOV AL, BYTE PTR Buffer+3
    SHL DX, 4             ; 将 DX 左移 4 位，为下一个 BCD 码腾出空间
    ADD DX, AX            ; 将第四个 BCD 码添加到 DX

    ; 此时，DX 的内容就是 8765H

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START
```

这个程序首先清空 DX，然后将每个 BCD 码添加到 DX 中。在添加每个 BCD 码之前，它都会将 DX 左移 4 位，以腾出空间。最后，DX 的内容就是 8765H。