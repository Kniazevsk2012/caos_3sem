	.text
	.global main

main:
	push {r4, r5, r6, lr}
	mov r0, #0
	mov r1, #51
	bl realloc
	mov r5, r0
	mov r6, #0
	mov r4, #51

loop:
	ldr r0, =stdin
	ldr r0, [r0]
	bl fgetc
	cmp r0, #-1
	beq reverse
	cmp r0, #32
	blo loop
	strb r0, [r5, r6]
	add r6, r6, #1
	cmp r6, r4
	blo loop
	mov r0, #2
	mul r1, r0, r4
	mov r0, r5
	mov r4, r1
	bl realloc
	mov r5, r0
	b loop

reverse:
	cmp r6, #0
	beq exit
	sub r6, r6, #1
	ldr r1, =stdout
	ldr r1, [r1]
	ldrb r0, [r5, r6]
	bl fputc
	b reverse

exit:
	mov r0, r5
	bl free
	pop {r4, r5, r6, lr}
	bx lr
