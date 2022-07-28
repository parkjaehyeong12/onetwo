#include<stdio.h>
int main()
{
	//10952
	if (0)
	{
		int a, b;
		for (;;)
		{
			scanf_s("%d %d", &a, &b);
			if (a == 0 && b == 0)
				break;
			printf("%d\n", a + b);
		}
	}
	//10807
	if (0)
	{
		int n, h, k;
		char arr[100];
		scanf_s("%d", &n);
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d ", &h);
			arr[i] = h;
		}
		scanf_s("%d", &k);
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == k)
				count++;
		}
		printf("%d", count);
	}


	return 0;
}