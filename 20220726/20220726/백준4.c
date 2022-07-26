#include<stdio.h>
int main()
{
#pragma region 백준 9498
	if (0)
	{
		int score;
		scanf_s("%d", &score);
		if (score >= 90 && score <= 100)
			printf("A");
		else if (score >= 80 && score <= 89)
			printf("B");
		else if (score >= 70 && score <= 79)
			printf("C");
		else if (score >= 60 && score <= 69)
			printf("D");
		else
			printf("F");
	}
#pragma endregion
#pragma region 백준2753
	if (0) {
		int year;
		scanf_s("%d", &year);
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			printf("1");
		else
			printf("0");
	}
#pragma endregion
#pragma region 백준14681
	if (0)
	{
		int a, b;
		scanf_s("%d %d", &a, &b);
		if (a > 0 && b > 0)
			printf("1");
		else if (a < 0 && b > 0)
			printf("2");
		else if (a < 0 && b < 0)
			printf("3");
		else if (a > 0 && b < 0)
			printf("4");
	}
#pragma endregion
	int h, m;
	scanf_s("%d %d", &h, &m);
	if(h>=24)
		j
	
	if (m >= 45)
		m -= 45;
	else
	{
		h -= 1;
		m += 15;
	}
	if (h < 0)
		h += 24;
	printf("%d %d", h, m);

	return 0;
}