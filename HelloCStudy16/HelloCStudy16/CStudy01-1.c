//�ǽ��غ��� 

#include<stdio.h>
double average(int student[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int k = student[i];
		sum += k;
	}
	printf("��� ���̴� %.2f���̴�", sum / (n * 1.0));
	return sum / (n * 1.0);
}

int* Arr1()
{
	static int arr[5] ={1,2,3,4,5}; //static ���� ��������� �迭�� ������� �ʴ´�.
	return arr;
}

//nums�տ� ������ *�� �� ���شٸ� �׳� �� �迭�� �ʱ� �κ��� �ּҰ��� ���� ���ۿ� ������.
//(int nums[]) �� ǥ���ص� �ȴ�.
void printArr(int *nums)  //5��
{
	for (int i = 0; i < 5; i++)
		printf("%d ", nums[i]);
}


int main()
{
	//1
	printf("�л��� ��? ");
	int n;
	scanf_s("%d", &n);
	int student[100];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &student[i]);
		int k = student[i];
	}

	//2,3
	printf("\n������� %.2f\n",average(student, n));

	//4�� 1�����迭 �����

	int* nums = Arr1();
	for (int i = 0; i < 5; i++)
		printf("%d ", nums[i]);

	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("%d ", *Arr1() + i); //made by ����

	printf("\n");

	//5��
	printArr(nums);


	return 0;
}