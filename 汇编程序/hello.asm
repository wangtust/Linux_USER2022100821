section .data
    hello db 'Hello, World!',0

section .text
    global _start

_start:
    ; write syscall
    mov rax, 1
    mov rdi, 1
    mov rsi, hello
    mov rdx, 13
    syscall

    ; exit syscall
    mov rax, 60
    xor rdi, rdi
    syscall