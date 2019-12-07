    .text
    .global main

main:
    push {r4, r5, r6, r7, lr}
    ldr r6, scanf_fmt_ptr
    ldr r7, printf_fmt_ptr
    sub sp, #8

    mov r0, r6
    mov r1, sp
    mov r2, sp
    add r2, r2, #4

    bl scanf
    ldr r4, [sp]
    ldr r5, [sp, #4]
    add r1, r4, r5
    mov r0, r7

    bl printf
    add sp, sp, #8
    pop {r4, r5, r6, r7, lr}
    bx lr

scanf_fmt_ptr:
    .word scanf_format
printf_fmt_ptr:
    .word printf_format

printf_format:
    .ascii "%d\0"
scanf_format:
    .ascii "%d%d\0"
