#include<stdio.h>
int inputNum()
{
	int a;
	printf("���ڸ� �Է��Ͻÿ� ");
	scanf_s("%d", &a);
	return a;
}

void printNum(int num)
{
	printf("%d\n", num);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = inputNum();
	int b = inputNum();
	printNum(a);
	printNum(b);
	swap(&a, &b);
	printNum(a);
	printNum(b);
}
