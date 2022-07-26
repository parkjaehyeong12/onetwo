#include<stdio.h>
int main()
{
	/*
	int a, b, c;
	scanf_s("%d %d %d", &a, &b,&c);
	printf("%d\n", (a + b)%c);
	printf("%d\n", (a % c + b % c) % c);
	printf("%d\n", (a * b)%c);
	printf("%d\n", (a % b * b % c)) % c);*/
	/*
	printf("|\\_/|\n");
	printf("|q p|   /}\n");
	printf("( 0 )\"\"\"\\\n");
	printf("|\"^\"`    |\n");
	printf("||_/=\\\\__|\n");*/

	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d\n", a * (b % 10));
	printf("%d\n", a * ((b % 100 - b % 10)/10));
	printf("%d\n", a * ((b - b % 100)/100));
	printf("%d", a * b);

	return 0;
}