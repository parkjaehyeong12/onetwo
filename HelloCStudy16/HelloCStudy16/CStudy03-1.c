//다차원배열 실습문제

#include<stdio.h>
int main()
{
	//1 학교 층별 강의실 각각에 저장된 학생의 수 저장해보기 //3층 4강의실 각각의 학생의 수
	int stu[3][4] = {
		{25,30,13,14},
		{16,19,24,29},
		{25,23,31,15}
	};

	//2
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d층 %d강의실 학생은 %d명이다.\n", i + 1,j+1,stu[i][j]);
	}

	printf("몇 층? 강의실 몇개? ");
	int floor, room, num;
	scanf_s("%d %d", &floor, &room);


	//3
	int students[1024][1024];
	
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < room; j++)
		{
			scanf_s("%d", &num);
			students[i][j] = num;
		}
	}
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < room; j++)
		{
			printf("%d층의 %d강의실에는 %d명의 학생이 있다.\n", i + 1, j + 1, students[i][j]);
		}
	}

	//3




	return 0;
}