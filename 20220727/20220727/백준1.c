#include<stdio.h>
int main()
{
#pragma region 15552
	if (0)
	{
		int n;
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a + b);
		}
	}
#pragma endregion
#pragma region 2439
	if (0)
	{
		int n;
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				printf(" ");
			}
			for (int k = 0; k <= i; k++)
				printf("*");
			printf("\n");
		}
	}
#pragma endregion
#pragma region 1085
	if (0)
	{
		int x, y, w, h;
		int dis1, dis2, dis3;
		scanf_s("%d %d %d %d", &x, &y, &w, &h);
		if (x * 2 <= w)
			dis1 = x;
		else
			dis1 = w - x;
		if (y * 2 <= h)
			dis2 = y;
		else
			dis2 = h - y;
		if (dis1 >= dis2)
			dis3 = dis2;
		else
			dis3 = dis1;
		printf("%d", dis3);
	}
#pragma endregion
#pragma region 10871
	if (0)
	{
		int n, x, a;
		scanf_s("%d %d", &n, &x);

		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &a);
			if (a < x)
				printf("%d ", a);
		}
	}
#pragma endregion

	/*
	int n, a;
	int sum = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a);
		sum += a;
	}
	printf("%d", sum);
*/

	int N, sum, i;
	char dest[100];

	scanf_s("%d", &N);

	rewind(stdin);
	
	gets(dest);

	i = 0;
	sum = 0;

	while (i < N)
	{
		sum += dest[i] - '0';
		i++;
	}
	printf("%d", sum);




	return 0;
}