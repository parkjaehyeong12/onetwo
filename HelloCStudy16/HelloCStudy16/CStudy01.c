#include<stdio.h>
//�迭�� �������̱� ������ �Լ��� �Ű������� ���̰� �Ǹ�
//�Լ����� ���� ��ȭ�� ���� �� �迭������ ���� ��ȭ�� �ִ�.

//����� ���� �ѱ���� �ƴϸ� �����Ⱚ�� �� �ִ� �� �̿��ϵ���

void increaseNum(int* numbers, int size, int n)
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] += n;
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
void decreaseNum(int* numbers, int size, int n)
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] -= n;
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
void printfArr(int* ages, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\t", ages[i]);
	printf("\n");
}

int printfArr2(int* ages, int size, int n)
{
	for (int i = size - 1; i >= 0; i--)
	{
		ages[i] -= n;
		if (ages[i] < 0)
			return -1;
		printf("%d ", ages[i]);
	}
	printf("\n");
}
//4��
void decreaseNum_q4(int numbers[], int size, int n)
{
	//�Ű������� ������ ���͵� �� �ǰ�
	//���� ���� �� ������ �Ǹ� ��� ����
	if (n < 0)
		return; //�̷��� �� ���� if else�� ��� �ص� �ȴ�.

	for (int i = 0; i < size; i++)
	{
		int num = numbers[i];
		num -= n;
		if (num < 0) //n�� ���� �� �������? ��� ����
			return;

		//void �ϰ� return; ���� �׳� ����

		numbers[i] -= n;
	}
}

int main()
{
	int ages[5] = { 23,25,30,29,50 };
	int ages2[3] = { 10,20,30 };

	int ages3[3];
	ages3[0] = 20;
	ages3[1] = 30;
	ages3[2] = 40;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", ages[i]);
		ages[i] = ages[i] = i * i + ages[i];//�ƹ����̳� �־
	}

	//�̷� ���� �־���?

	int size = sizeof(ages) / sizeof(int);

	if(0)
	{ 

	printf("%d\n\n", size);

	increaseNum(ages2, 3, 100);
	printf("\n\n");

	increaseNum(ages, size, 5);


	for (int i = 0; i < size; i++) {
		printf("%d ", ages[i]);
	} //����������

	printf("\n");
	printfArr(ages, size);

	printf("\n");
	decreaseNum(ages, size, 5);

	printf("\n");
	printfArr2(ages, size, 35);
}
	
	printf("---------1��-----------\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", ages2[i]);
	increaseNum(ages2, 3, 100);
	
	printf("---- ��ȭ ��----\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", ages2[i]);

	printf("\n---------2�� --------\n");
	printfArr(ages, size);

	printf("\n---------3�� --------\n");
	decreaseNum(ages, size, 15);
	printfArr(ages, size);

	printf("\n---------4�� --------\n");

	ages3[0] = 150;
	ages3[1] = 50;
	ages3[2] = 500;
	decreaseNum_q4(ages3, 3, 100);
	
	printfArr(ages3, 3);


	return 0;
}