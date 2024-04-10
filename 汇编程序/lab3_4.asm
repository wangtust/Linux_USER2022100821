data segment
    DATAX dw 0148H, 2316H
    DATAY dw 0237H, 4052H
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

    ; DATAX和DATAY按字相加，和存放在DATAY中
    mov ax, [DATAX]
    add [DATAY], ax
    mov ax, [DATAX+2]
    add [DATAY+2], ax

    ; DATAX和DATAY按双字（高字在高地址，低字在低地址）相加，和存放在从DATAY开始的双字单元中
    mov ax, [DATAX]
    add [DATAY], ax
    adc [DATAY+2], 0
    mov ax, [DATAX+2]
    add [DATAY+2], ax
    adc [DATAY+4], 0
            
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.