#include <iostream>

int main()
{
	unsigned char a, b, x;
	char y;
	bool c = 0, d = 0;
	scanf_s("%hhu %hhu", &a, &b);

	_asm
	{
		mov al,a
		mov bl,b
		add al,bl
		jno sign
		mov c,1
	sign:
		jnc unsign
		mov d,1
	unsign:
		mov y,al
		mov x,al
	}

	printf("\na + b = %d (signed)\n", y);
	printf("a + b = %hhu (unsigned)\n", x);

	if (c == 1)
		printf("overflow (signed)\n");
	else
		printf("no overflow (signed)\n");

	if (d == 1)
		printf("overflow (unsigned)\n");
	else
		printf("no overflow (unsigned)\n");
}