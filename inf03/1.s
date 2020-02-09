	.text
	.global main

main:
	push {lr}

loop:
	ldr r0, =stdin
	ldr r0, [r0]
	bl fgetc
	cmp r0, #-1
	beq return
	cmp r0, #57
	bhi loop
	cmp r0, #48
	blo loop
	ldr r1, =stdout
	ldr r1, [r1]
	bl fputc
	b loop
	
return:
	pop {lr}
	bx lr
