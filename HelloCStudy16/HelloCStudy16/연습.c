#include<stdio.h>
int main()
{
	if (0)
	{
		int ages[10][3] = { 10,20,30,40,50,60 };
		ages[5] += 0;
		printf("%d", ages[5]);
	}
	return 0;
}