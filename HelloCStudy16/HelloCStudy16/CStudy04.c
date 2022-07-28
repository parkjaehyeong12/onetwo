#include<stdio.h>
//실습 2 풀이
int main()
{
	int counts[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("강의실 안 학생수 입력 ");
			scanf_s("%d", &counts[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t",counts[i][j]); // \t는 탭키라 4칸정도 점프뛴다. 
		}
		printf("\n");
	}

	//3번 페이크문제
	//해석1 counts[0] ~counts[i-1]번째 값을 가져와서 쓴다.
	//해석2 그냥 1차원 배열 만들고 그 안에 값 넣는다.
	
	int rooms[3]; //3층
    //각 인덱스에 값을 넣으면 그게 바로 각 층의 강의실 개수
	scanf_s("%d %d %d", &rooms[0], &rooms[1], &rooms[2]);
	printf("%d %d %d", rooms[0], rooms[1], rooms[2]);


	return 0;
}