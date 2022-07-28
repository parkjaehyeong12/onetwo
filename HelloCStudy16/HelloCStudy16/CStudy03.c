//이제는 다차원배열로 해볼것임

#include<stdio.h>


int main()
{
	//선언하자마자 입력
	int ages[3][5] = {
		{20,25,32,33,31},
		{21,52,23,30,35},
		{27,24,22,23,25}
	};
	//집어넣기
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; i < 5; j++)
		{
			ages[i][j] = 10; //숫자배열은 집어넣는 것이 가능하다.
			scanf_s("%d", &ages[i][j]);
			printf("%d\n", ages[i][j]);
		}
	}



	return 0;
}