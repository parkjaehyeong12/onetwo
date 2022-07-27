#include<stdio.h>

int calcAge()
{
	int year;
	printf("몇 년도 태어남? ");
	scanf_s("%d", &year);
	return 2023 - year; //한국식 나이
}
int main()
{
	//4
	printf("저는 %d살입니다.\n",calcAge());


	return 0;
}