#include<stdio.h>
int main()
{
	int n;
	int sum = 1;
	scanf_s("%d", &n);
	if (n > 1)
	{
		for (int i = 1; i <= n; i++)
		{
			sum *= i;
		}
		printf("%d", sum);
	}
	else if(n ==0)
		printf("1");

	return 0;
}