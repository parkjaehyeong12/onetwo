#include<stdio.h>
void printArr(int* nums)  //5��
{
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%d\t", nums[i]);
}
//2
double average(int ages[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ages[i];
	return sum / (double)size;
	// (double) ���� �׳��ϸ� �Ҽ����� �߸���.
	//�Ǽ��� ���ؾ� �ϹǷ� �����ϳ� Ȥ�� �Ѵ� �Ǽ��� ����ȯ����� ��.
}
int* myages()
{
	static int ages[3]; //static �Ⱦ��� �����
	for (int i = 0; i < 3; i++)
	{
		printf("�л��� ���� �Է� ");
		scanf_s("%d", &ages[i]);
	}
	return ages;
}


int main()
{
	int ages[3];
	for (int i = 0; i < 3; i++)
	{
		printf("�л��� ���� �Է� ");
		scanf_s("%d", &ages[i]);
	}
	//3
	printf("��ճ��� : %.2f\n", average(ages, 3));

	//4 ���ϰ� �޾ƿ���
	int* values = myages();
	for (int i = 0; i < 3; i++)
		printf("%d", values[i]);
	
	//5 �׳� ����ϱ�
	printArr(values, 3);

	return 0;
}