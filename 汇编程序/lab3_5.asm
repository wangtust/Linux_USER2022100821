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

    ; (1) 如果用BX存放数组ARRAY的初始地址，请编写指令将ARRAY中的数据0传送给ZERO单元。
    mov bx, OFFSET ARRAY ; 将数组ARRAY的初始地址存放到BX寄存器
    mov ax, [bx+12] ; 加载数组中的第7个元素（每个元素为2字节，所以偏移量为6*2=12）
    mov [ZERO], ax ; 将AX寄存器的值存储到ZERO单元

    ; (2) 如果用BX存放ARRAY中数据0在数组中的位移量，请编写指令将数据0传送给ZERO单元。
    mov bx, 12 ; 将BX寄存器的值设置为0元素在数组中的位移量
    mov ax, [ARRAY+bx] ; 加载数组中的第7个元素
    mov [ZERO], ax ; 将AX寄存器的值存储到ZERO单元
            
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.