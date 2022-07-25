#include<stdio.h>
void no_changeValue(int a, int b)
{
	a = b;
}


int main()
{
	//1
	int a = 3;
	no_changeValue(a, 300);
	printf("%d\n", a);
	
	//2
	
	return 0;
}