#include<stdio.h>
void printArr(int* nums)  //5번
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
	// (double) 없이 그냥하면 소수점이 잘린다.
	//실수를 구해야 하므로 둘중하나 혹은 둘다 실수로 형변환해줘야 함.
}
int* myages()
{
	static int ages[3]; //static 안쓰면 사라짐
	for (int i = 0; i < 3; i++)
	{
		printf("학생의 나이 입력 ");
		scanf_s("%d", &ages[i]);
	}
	return ages;
}


int main()
{
	int ages[3];
	for (int i = 0; i < 3; i++)
	{
		printf("학생의 나이 입력 ");
		scanf_s("%d", &ages[i]);
	}
	//3
	printf("평균나이 : %.2f\n", average(ages, 3));

	//4 리턴값 받아오기
	int* values = myages();
	for (int i = 0; i < 3; i++)
		printf("%d", values[i]);
	
	//5 그냥 출력하기
	printArr(values, 3);

	return 0;
}