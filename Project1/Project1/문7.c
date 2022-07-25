#include<stdio.h>
int seven(int a, int b, char c)
{
	int sum;
	if (c == '+')
	{
		sum = a;
		printf("%d", a);
		for (int i = a + 1; i <= b; i++)
		{
			sum += i;
			printf("+%d", i);
		}
		printf("=%d\n", sum);
		return sum;
	}
	else if (c == '*' || c == 'x')
	{
		sum = a;
		printf("%d", a);
		for (int i = a + 1; i <= b; i++)
		{
			sum *= i;
			printf("x%d", i);
		}
		printf("=%d\n", sum);
		return sum;
	}
	else
	{
		printf("잘못되었습니다.\n");
		return -1;
	}
}
int main()
{
	int a, b;
	char c;
	printf("숫자두개 입력 ");
	scanf_s("%d %d", &a, &b);
	printf("문자입력 ");
	rewind(stdin);
	scanf_s("%c", &c, 1);
	int result = seven(a, b, c);
	printf("%d", result);
	return 0;
}