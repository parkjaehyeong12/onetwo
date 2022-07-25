#include<stdio.h>
int five()
{
	int sum = 1;
	printf("1");
	for (int i = 2; i <= 100; i++)
	{
		printf("+%d", i);
		sum += i;
	}
	printf("=%d\n", sum);
	return sum;
}
int main()
{
	int result = five();
	printf("°á°ú %d", result);
	return 0;
}