    .global _start
    .intel_syntax noprefix
    .text
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, s_ptr
    mov edx, 14
    int 0x80
    mov eax, 1
    mov ebx, 0
    int 0x80
    .data
str:
    .string "Hello, World!\n"
s_ptr: 
    .long str
