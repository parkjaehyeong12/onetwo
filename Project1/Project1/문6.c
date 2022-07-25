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
	printf("숫자 두개 ");
	scanf_s("%d %d", &a, &b);
	int result = six(a, b);
	printf("결과 %d", result);
	return 0;
}