.global summ
.intel_syntax noprefix
.text

summ:
	push ebp
	mov ebp, esp
	mov ecx, [ebp + 8]
	push ebx

.loop:
	mov eax, ecx
	dec eax
	mov ebx, [ebp + 12]
	mov edx, [ebx + 4 * eax]
	mov ebx, [ebp + 16]
	add edx, [ebx + 4 * eax]
	mov ebx, [ebp + 20]
	mov [ebx + 4 * eax], edx
	loop .loop
	pop ebx
	pop ebp
	ret
