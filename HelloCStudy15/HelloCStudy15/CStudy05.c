#include<stdio.h>
int calculAge(int y)
{
	return 2023 - y;
}

int main()
{
	int year;
	printf("����? ");
	scanf_s("%d", &year);
	printf("%d���̿���", calculAge(year));
	
	return 0;
}