.global summ
.intel_syntax noprefix
.text

summ:
	push ebx
	mov ecx, N

.loop:
	mov eax, ecx
	dec eax
	mov ebx, A
	mov edx, [ebx + 4 * eax]
	mov ebx, B
	add edx, [ebx + 4 * eax]
	mov ebx, R
	mov [ebx + 4 * eax], edx
	loop .loop
	pop ebx
	ret

.global everyday795
everyday795:
	push ebp
	mov ebp, esp
	sub esp, 4
	
	mov eax, ebp
	sub eax, 4
	push eax
	mov eax, offset scanf_format_string
	push eax
	call scanf
	add esp, 8

	mov eax, [ebp - 4]
	imul eax, [ebp + 8]
	add eax, [ebp + 12]
	push eax
	mov eax, offset printf_format_string
	push eax
	call printf
	add esp, 8

	mov esp, ebp
	pop ebp
	ret

scanf_format_string:
	.string "%d"
printf_format_string:
	.string "%d\n"
