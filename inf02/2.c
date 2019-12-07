    .text      
    .global solve

solve:
	push {r4, r5, r6}
	mov r4, #0 // x count
	mov r5, #0 // summ

for:
	mov r5, r3 // r5 now holds D

	mov r6, r4 // just х
	mul r6, r6, r2 // C*x
	add r5, r5, r6 // D + C*x

	mov r6, r4 // just x
	mul r6, r6, r6 // x^2
	mul r6, r6, r1 // B*x^2
	add r5, r5, r6 // D + C*x + B*x^2

	mov r6, r4 // just x
	mul r6, r6, r6 // x^2
	mul r6, r6, r4 // x^3
	mul r6, r6, r0 // A*x^3
	add r5, r5, r6 // D + C*x + B*x^2 + C*x^3

	cmp r5, #0
	beq exit

	add r4, r4, #1
	b for

exit:
	mov r0, r4
	pop {r4, r5, r6}
	bx lr
