#include<stdio.h>
int one()
{
	printf("변수 a,b,c의 값을 입력 ");
	int a, b, c;
	int sum = 0;
	scanf_s("%d %d %d", &a, &b, &c);
	for (int i = a; i <= b; i++)
	{
		if (i % c == 0)
			continue;
		sum += i;
	}

	return sum;
}
int main()
{
	int result = one();
	printf("합한 값은 %d", result);
	return 0;
}