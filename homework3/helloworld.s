.section .data

message:
    .ascii "hello world!\n"
    length = . - message

    .section .text
    .global main

main:
    movq $1, %rax
    movq $1, %rdi
    lea message(%rip), %rsi
    movq $length, %rdx
    syscall

    movq $60, %rax
    xor %rdi, %rdi
    syscall
