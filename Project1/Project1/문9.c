#include<stdio.h>
int nine(int n)
{
	if (n == 1)
	{
		printf("1 = ");
		return 1;
	}
	printf("%d x ", n);
	return n * nine(n - 1);
}
int main()
{
	int n;
	printf("숫자n 입력 ");
	scanf_s("%d", &n);
	int result = nine(n);
	printf("%d", result);
	return 0;
}