#include<stdio.h>
void four(char a, char b)
{
	char color[9] = "color ";
	color[6] = a;
	color[7] = b;
	system(color);
}
int main()
{
	char a, b;
	printf("첫번째 문자 입력 ");
	scanf_s("%c", &a, 1);
	rewind(stdin);
	printf("두번째 입력 ");
	scanf_s("%c", &b, 1);
	four(a, b);
	return 0;
}