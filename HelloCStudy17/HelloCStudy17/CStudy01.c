#include<stdio.h>
//1. 2D 게임 캐릭터 좌표 저장하는 구조체 만들기
//1개의 변수가 1개 이상의값을 가짐 !

struct Game2Dpos
{
	int x;
	int y;
};

int main()
{
	//구조체 : struct 스트럭트
	//사용자가 직접 만든 자료형
	//크기도 다양, 배열이랑은 다름
	//한개의 변수가 여러가지 속성을 가진다.

	struct Game2Dpos p1 = { 10,20 };
	printf("%d\n", sizeof(p1));
	//사이즈 8
	//4바이트가 한 변수에 두 개 있음
	
	struct Game2Dpos p2 = { .x = 10, .y = 20 };
	
	struct Game2Dpos p3;
	p3.x = 10;
	p3.y = 20;
	
	struct Game2Dpos p4;
	scanf_s("%d %d", &p4.x, &p4.y);
	printf("x좌표 %d, y좌표 %d\n", p4.x, p4.y);




	return 0;
}