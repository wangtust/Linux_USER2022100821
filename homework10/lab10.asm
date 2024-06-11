;press esc to exit         			; 清屏或上卷宏定义
data segment
    assume ds:data
    msg0  db 'I LIKE IBM PC...AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA$'
    msg1  db '8080 PROGRAMMING IS RUN...$'
    msg2  db 'TIME TO BUY MANY DISKETTES...$'
    msg3  db 'THIS PROGRAM WORKS...$'
    msg4  db 'TURN OFF THAT PRINTER!...$'
    msg5  db 'I HAVE MANY...$'
    msg6  db 'THE PSP CAN BE USEFUL...$'
    msg7  db 'BASIC WAS EASIER THEN THIS...$'
    msg8  db 'DOS IS INDISPESABLE...$'
    msg9  db 'LAST MESSAGE OF THE DAY..$'  
    ;10个练习的句子
    pt1 db "This is a typing software ,press ENTER to start."
        db 0DH,0AH
        db "It can record the time you cost in typing ,and the correct rate."
        db 0DH,0AH
        db "When you want to leave ,just press the ESC.$"     
     
    pt2 db "Enter a number between 0 to 9 to slect a sentence for your practice."
        db 0DH,0AH
        db 0DH,0AH
        db "$" 
    pt3 db "Please enter the sentence you chose:" 
        db 0DH,0AH
        db 0DH,0AH
        db "$"
    pt4 db "Do you want to restart. Press ENTER to restart,or press ESC to leave.$" 
    pt5 db 0DH,0AH
        db "Thank you for using my type software.$" 
    score db "Your score is :"
          db 0DH,0AH
          db  "          min:    sec:    msec:    your error:    % .$"
    s  dw 0,0,0
      
    timebegin dw 0,0;存放开始结束时间
    timeend dw 0,0   
    ; 跳转表,用来存用户选择的句子
    jmp_table dw offset msg0, offset msg1, offset msg2, offset msg3, offset msg4, 
           dw offset msg5, offset msg6, offset msg7, offset msg8, offset msg9
    temp dw 0,0,0;si地址，就是选择的句子地址和句子长度,和输错的字符数
data ends


stack segment 
    db 256 dup(0)
stack ends

scroll    macro     n,ulr,ulc,lrr,lrc,att	;宏定义
          mov       ah,6				;清屏或上卷
          mov       al,n		;n=上卷行数；n=0时，整个窗口空白
          mov       ch,ulr		;左上角行号
          mov       cl,ulc		;左上角列号
          mov       dh,lrr		;右下角行号
          mov       dl,lrc		;右下角列号
          mov       bh,att		;卷入行属性
          int       10h
          endm  
curse     macro     cury,curx    
          mov       ah,2		     	;置光标位置
          mov       dh,cury			;行号
          mov       dl,curx			;列号
          mov       bh,0			;当前页
          int       10h
          endm
slect     macro     
       ; 获取用户输入
          lea dx,pt2
          mov ah,09h
          int 21h  
   not_digit:
          mov ah, 08h    ;输入数字但不显示
          int 21h 
          cmp al, '0'    ;比较输入字符和'0'
          jb not_digit   ;如果输入字符小于'0'，跳转到not_digit
          cmp al, '9'    ;比较输入字符和'9'
          ja not_digit   ;如果输入字符大于'9'，跳转到not_digit
         
          sub al, '0'    ; 将字符转换为数字
          cbw
          mov bx, ax
          add bx, bx     ; 因为每个地址是2字节，所以我们需要将索引乘以2
          mov si, [jmp_table + bx]
          mov temp[0],si 
          mov bx,0 
          
          lea dx,pt3 ;提示输入句子
          mov ah,09h
          int 21h  
          
          next_char:
          mov ah, 0Eh		; BIOS中断10h的子功能0Eh，用于显示字符
          mov al, [si]		; 获取字符串中的当前字符
          int 10h			; 执行BIOS中断10h
          inc si			; 移动到字符串中的下一个字符
          inc bx
          cmp byte ptr [si], '$'	; 检查是否到达字符串的末尾  
       jne next_char		; 如果没有到达字符串的末尾，就继续显示下一个字符  
          mov temp[2],bx;存这个字符串长度
          endm

cseg      segment
          assume cs:cseg    
                    
         
main      proc      far  
          mov ax, data
          mov ds, ax ; 将数据段地址加载到DS 
          
          scroll    0,0,0,24,79,02		;清屏
          scroll    13,7,19,19,51,50h		;开外窗口，品红底 
          scroll    11,8,20,18,50,2fh	;开内窗口，绿底白字 
          curse     0,0
          
          lea dx,pt1
          mov ah,09h
          int 21h   
       s0:  
          mov       ah,0			;等待输入
          int       16h	
          cmp       al,1BH			;是否为esc键？
          jz        leave				;是，退出
          
          cmp       al,0DH			;是否为enter键？
          jz        begin				;是,进入打字计时
       jmp s0
          
begin:    

          scroll    0,0,0,24,79,02		;清屏
          scroll    13,7,19,19,51,50h		;开外窗口，品红底 
          scroll    11,8,20,18,50,2fh	;开内窗口，绿底白字 
          curse     0,0
          slect    ;让用户选择一个句子练习
          curse     18,20			;置光标于18行20列  
                                       
          ;读取时间
          mov ah,0
          mov al,10h
          int 1Ah
          mov timebegin[0],cx
          mov timebegin[2],dx
          mov bx,0
          mov si,temp[0]
          
get1:     mov       cx,30			;置一行字符数
get2:     mov       ah,0			;等待输入
          int       16h	
          cmp       al,1BH			;是否为esc键？
          jz        leave				;是，退出 
          cmp       al,[si]          
          jz        skip;如果没打错就不要加bx记错   
      error: 
          inc bx 
          push cx  ;设置显示红色需要用到cx，先给他保护起来
          push bx 
          mov bh, 0      ; 页面号，通常为0
          mov bl, 0Ch    ; 颜色代码，这里0Ch代表亮红色
          mov cx, 1      ; 重复次数
          mov ah, 09h    ; 设置子功能
          int 10h        ; 调用中断，显示字符

          mov bh, 0      ; 页面号，通常为0
          mov ah, 03h    ; 设置子功能
          int 10h        ; 调用中断，获取光标位置

          inc dl         ; 增加列号

          mov bh, 0      ; 页面号，通常为0
          mov ah, 02h    ; 设置子功能
          int 10h        ; 调用中断，设置新的光标位置 
          pop bx
          pop cx  
          inc si
          cmp [si],'$'
          jz store ;打字结束跳转到存储结果                                    
loop      get2
       
       
       skip:

   
          mov       ah,0eh			;显示输入的字符
          int       10h  
          inc si  ;到达字符串末尾了就结束
          cmp [si],'$'
          jz store  
          
          loop      get2
          scroll    1,8,20,18,50,2fh			;上卷一行
          curse     18,20 
          jmp       get1    
          
store:     
          mov temp[4],bx;把错误次数保存
          mov ah,0
          mov al,10h
          int 1Ah
          mov timeend[0],cx  ;保存结束时间
          mov timeend[2],dx
          jmp ending
          
time:                         ;计算打字用时和错误率的
          mov ax,timeend[2]
          mov bx,timebegin[2]
          sub ax,bx
          xor dx,dx
          mov bx,1080;此时ax存的就是分钟数
          div bx
          mov s[0],ax 
          mov ax,dx  ;将余数存入ax，也就有多少个1/18秒
          xor dx,dx
          mov bx,18
          div bx
          mov s[2],ax
          mov ax,dx
          xor dx,dx
          mov bx,5   ;1/18秒除以5大概就是毫秒
          div bx
          mov s[4],ax 
          
          mov ax,s[0] 
          mov ah, 0        ; 清除AH寄存器
          mov bl, 10       ; 设置除数为10
          div bl
          add al,30h
          add ah,30h
          mov score[31],al
          mov score[32],ah  ;min计算好了
          
          mov ax,s[2] 
          mov ah, 0        ; 清除AH寄存器
          mov bl, 10       ; 设置除数为10
          div bl
          add al,30h
          add ah,30h
          mov score[39],al
          mov score[40],ah  ;秒设置好了
          
          mov ax,s[4] 
          mov ah, 0        ; 清除AH寄存器
          mov bl, 10       ; 设置除数为10
          div bl
          add al,30h
          add ah,30h
          mov score[48],al
          mov score[49],ah ;毫秒存好了
          
          ;开始计算错误率
          mov ax,temp[4];存的是打错的个数
          xor dx,dx  
          mov bx,100
          imul  bx  ; 将AX寄存器中的值乘以100  不要超38324，也就是在38个字符内
          mov bx,temp[2];存的是句子长度
          div bx        ; 将AX寄存器中的值除以BX寄存器中的值
                         ; 商存储在AX寄存器中，余数存储在DX寄存器中
     
          mov ah, 0        ; 清除AH寄存器
          mov bl, 10       ; 设置除数为10,将他转换成10进制
          div bl
          add al,30h
          add ah,30h  
          mov score[63],al
          mov score[64],ah ;错误率存好了  
          jmp result                   

ending:   
        jmp time
          
          
          scroll    0,0,0,24,79,02		;清屏
          scroll    13,7,19,19,51,50h		;开外窗口，品红底 
          scroll    11,8,20,18,50,2fh	;开内窗口，绿底白字
          curse      0,0			;置光标 
          
          lea dx, pt4
          mov ah,09h
          int 21h   
          
          
          mov       ah,0			;等待输入
          int       16h	
          cmp       al,1BH			;是否为esc键？
          jz        leave				;是，退出
          
          cmp       al,0DH			;是否为enter键？
          jz        begin				;是,进入打字计时
leave:    
         curse      23,0			;置光标
          lea dx, pt4   ;显示提示
          mov ah,09h
          int 21h 
                    mov       ah,0			;等待输入
          int       16h	
          cmp       al,1BH			;是否为esc键？
          jz        releave				;是，退出
          
          cmp       al,0DH			;是否为enter键？
          jz        begin				;是,进入打字计时

result:
          curse      20,0			;置光标于18行20列  
          lea dx,score
          mov ah,09h
          int 21h 
          jmp leave
            
releave:          
          lea dx, pt5   ;显示提示
          mov ah,09h
          int 21h 
          
          mov ah, 08h    ;输入数字但不显示
          int 21h       
          mov       ah,4ch
          int       21h  

          
main      endp
cseg      ends
          end       main  
          
          


You laugh at me for being different, but I laugh at you for being the same.
Experience is a hard teacher because she gives the test first, the lesson afterwards.