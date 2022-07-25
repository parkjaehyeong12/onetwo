#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	//2
	int a = 3;
	int b = 5;
	swap(&a, &b);
	printf("%d %d", a, b);

	return 0;
}