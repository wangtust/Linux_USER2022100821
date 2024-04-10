data segment
    X dw 16 ; 定义变量X并初始化为16
    Y dw 2  ; 定义变量Y并初始化为2
    W dw 8  ; 定义变量W并初始化为8
    R dw 32 ; 定义变量R并初始化为32
    Z dw ?  ; 定义变量Z，不进行初始化
    pkey db "press any key...$" ; 定义一个字符串
ends

stack segment
    dw   128  dup(0) ; 定义一个128字节的栈，所有元素初始化为0
ends

code segment
start:
; set segment registers:
    mov ax, data ; 将数据段地址加载到ax寄存器
    mov ds, ax   ; 将ax寄存器的值设置为数据段寄存器的值
    mov es, ax   ; 将ax寄存器的值设置为附加段寄存器的值

    ; Z←W-(X+6)-(R+9)
    mov ax, [X]  ; 将X的值加载到ax寄存器
    add ax, 6    ; 将ax寄存器的值加6
    mov bx, [R]  ; 将R的值加载到bx寄存器
    add bx, 9    ; 将bx寄存器的值加9
    add ax, bx   ; 将ax寄存器的值和bx寄存器的值相加
    mov bx, [W]  ; 将W的值加载到bx寄存器
    sub bx, ax   ; 将bx寄存器的值减去ax寄存器的值
    mov [Z], bx  ; 将bx寄存器的值存储到Z

    ; Z←(W*X)/(Y+6)，R←余数
    mov ax, [W]  ; 将W的值加载到ax寄存器
    mov bx, [X]  ; 将X的值加载到bx寄存器
    imul bx      ; 将ax寄存器的值和bx寄存器的值相乘，结果存储在DX:AX中
    mov bx, [Y]  ; 将Y的值加载到bx寄存器
    add bx, 6    ; 将bx寄存器的值加6
    idiv bx      ; 将DX:AX的值除以bx寄存器的值，商存储在ax寄存器，余数存储在dx寄存器
    mov [Z], ax  ; 将ax寄存器的值存储到Z
    mov [R], dx  ; 将dx寄存器的值存储到R
            
    lea dx, pkey ; 将字符串pkey的地址加载到dx寄存器
    mov ah, 9    ; 设置ah寄存器的值为9，对应DOS的打印字符串功能
    int 21h      ; 调用DOS中断
    
    ; wait for any key....    
    mov ah, 1    ; 设置ah寄存器的值为1，对应DOS的键盘输入功能
    int 21h      ; 调用DOS中断
    
    mov ax, 4c00h ; 设置ax寄存器的值为4c00h，对应DOS的退出程序功能
    int 21h      ; 调用DOS中断
ends

end start ; 设置程序入口点为start，并停止汇编