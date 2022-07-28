//실습해보기 

#include<stdio.h>
double average(int student[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int k = student[i];
		sum += k;
	}
	printf("평균 나이는 %.2f살이다", sum / (n * 1.0));
	return sum / (n * 1.0);
}

int* Arr1()
{
	static int arr[5] ={1,2,3,4,5}; //static 으로 지정해줘야 배열이 사라지지 않는다.
	return arr;
}

//nums앞에 포인터 *를 안 써준다면 그냥 그 배열의 초기 부분의 주소값만 들어올 수밖에 없으요.
//(int nums[]) 로 표현해도 된다.
void printArr(int *nums)  //5번
{
	for (int i = 0; i < 5; i++)
		printf("%d ", nums[i]);
}


int main()
{
	//1
	printf("학생들 수? ");
	int n;
	scanf_s("%d", &n);
	int student[100];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &student[i]);
		int k = student[i];
	}

	//2,3
	printf("\n결과값은 %.2f\n",average(student, n));

	//4번 1차원배열 만들기

	int* nums = Arr1();
	for (int i = 0; i < 5; i++)
		printf("%d ", nums[i]);

	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("%d ", *Arr1() + i); //made by 보규

	printf("\n");

	//5번
	printArr(nums);


	return 0;
}