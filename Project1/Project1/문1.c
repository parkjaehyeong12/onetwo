#include<stdio.h>
int one()
{
	printf("���� a,b,c�� ���� �Է� ");
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
	printf("���� ���� %d", result);
	return 0;
}