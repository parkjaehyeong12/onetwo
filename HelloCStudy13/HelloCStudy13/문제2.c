#include<stdio.h>
struct whatnumber
{
	int alpha;
	int beta;
}typedef num;

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int inputnum()
{
	printf("���� �Է� ");
	int num;
	scanf_s("%d", &num);
	return num;
}

void printNum(int num)
{
	printf("%d\n", num);
}

int main()
{
	//2��
	num n;
	n.alpha = 3;
	n.beta = 5;
	int* alphawhere = &n.alpha;
	int* betawhere = &n.beta;
	swap(alphawhere, betawhere);
	printf("%d %d\n", n.alpha, n.beta);

	//3��
	printf("���İ��� ��Ÿ���� �Է��ض� ");
	scanf_s("%d %d", &n.alpha, &n.beta);
	printf("%d %d\n", n.alpha, n.beta);
	swap(alphawhere, betawhere);
	printf("%d %d", n.alpha, n.beta);

	//4��
	int a = inputNum();
	int b = inputNum();
	printNum(a);
	printNum(b);
	swap(&a, &b);
	printNum(a);
	printNum(b);
	
	return 0;
}