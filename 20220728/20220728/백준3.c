#include<stdio.h>
int main()
{
	if (0)
	{
		int n;
		scanf_s("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			printf("%d\n", i);
		}
	}

	if(0)
	{ 
	//10872¹ø
	int n;
	int sum = 1;
	scanf_s("%d", &n);
	if (n == 1)
		printf("%d", n);
	else if(n>=0 &&n<=12)
	{
		for (int i = 1; i <= n; i++)
		{
			sum = sum* i;
		}
		printf("%d", sum);
	}
}


	return 0;
}