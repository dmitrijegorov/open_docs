#include <stdio.h>

int main() {
    char s[4]; 
    short int n=16, k=0;
	char a[16]; 
	short int b[16], c[16];
	for (int i=0; i<n; i++){
		gets(s);
		sscanf(s, "%i", &a[i]);
	}
	printf("A:\n");
	for (int i=0; i<n; i++){
		printf("%i\n", a[i]);
	}
	printf("\n");

	__asm{
	mov cx, n
	lea esi, a
	lea edi, b
	lea ebx, c
	mov dl, [esi]
BEG:
	mov al, [esi]
	imul dl
	mov [edi], ax
	inc edi
	inc edi

	JC NU
	JMP NEXT
NU:
	mov [ebx], esi
	inc k
	inc ebx
	inc ebx
NEXT:
	inc esi
	dec cx
	cmp cx, 0
	JNE BEG
EXIT:
    nop

    }
	printf("B:\n");
	for (int i=0; i<n; i++){
		printf("%i\n", b[i]);
	}
	printf("\n");
	printf("C:\n");
	for (int i=0; i<k; i++){
		printf("%i\n", c[i]);
	}
	printf("k=%i\n", k);
    return 0;
}
