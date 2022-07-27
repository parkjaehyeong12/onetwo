#include<stdio.h>
int calculAge(int y)
{
	return 2023 - y;
}

int main()
{
	int year;
	printf("몇년생? ");
	scanf_s("%d", &year);
	printf("%d살이에요", calculAge(year));
	
	return 0;
}