#include<stdio.h>
int eight(int n)
{
	int sum = 1;
	printf("1");
	for (int i = 2; i <= n; i++)
	{
		sum *= i;
		printf("x%d", i);
	}
	printf("=%d", sum);
}
int main()
{
	printf("숫자n 입력 ");
	int n;
	scanf_s("%d", &n);
	eight(n);
	return 0;
}