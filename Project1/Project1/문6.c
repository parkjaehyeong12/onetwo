#include<stdio.h>
int six(int a, int b)
{
	printf("%d", a);
	int sum = a;
	for (int i = a + 1; i <= b; i++)
	{
		printf(" X %d", i);
		sum *= i;
	}
	printf(" = %d\n", sum);
	return sum;
}
int main()
{
	int a, b;
	printf("���� �ΰ� ");
	scanf_s("%d %d", &a, &b);
	int result = six(a, b);
	printf("��� %d", result);
	return 0;
}