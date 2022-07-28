#include<stdio.h>
//배열은 포인터이기 때문에 함수의 매개변수로 쓰이게 되면
//함수에서 값의 변화가 있을 때 배열에서도 값의 변화가 있다.

//사이즈를 같이 넘기든지 아니면 쓰레기값이 들어가 있는 걸 이용하든지

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
//4번
void decreaseNum_q4(int numbers[], int size, int n)
{
	//매개변수로 음수가 들어와도 안 되고
	//값을 뺐을 때 음수가 되면 즉시 종료
	if (n < 0)
		return; //이렇게 안 쓰고 if else로 묶어서 해도 된다.

	for (int i = 0; i < size; i++)
	{
		int num = numbers[i];
		num -= n;
		if (num < 0) //n을 뺐는 데 음수라면? 즉시 종료
			return;

		//void 하고 return; 쓰면 그냥 종료

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
		ages[i] = ages[i] = i * i + ages[i];//아무값이나 넣어봄
	}

	//이런 것이 있었다?

	int size = sizeof(ages) / sizeof(int);

	if(0)
	{ 

	printf("%d\n\n", size);

	increaseNum(ages2, 3, 100);
	printf("\n\n");

	increaseNum(ages, size, 5);


	for (int i = 0; i < size; i++) {
		printf("%d ", ages[i]);
	} //서준이형거

	printf("\n");
	printfArr(ages, size);

	printf("\n");
	decreaseNum(ages, size, 5);

	printf("\n");
	printfArr2(ages, size, 35);
}
	
	printf("---------1번-----------\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", ages2[i]);
	increaseNum(ages2, 3, 100);
	
	printf("---- 변화 후----\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", ages2[i]);

	printf("\n---------2번 --------\n");
	printfArr(ages, size);

	printf("\n---------3번 --------\n");
	decreaseNum(ages, size, 15);
	printfArr(ages, size);

	printf("\n---------4번 --------\n");

	ages3[0] = 150;
	ages3[1] = 50;
	ages3[2] = 500;
	decreaseNum_q4(ages3, 3, 100);
	
	printfArr(ages3, 3);


	return 0;
}