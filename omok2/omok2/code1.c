#include<stdio.h>
#include<Windows.h>
#include<conio.h>

int Rule();
int goBoard[20][20] = { 0 };
void goxy(int x, int y);
int Color = 2;
void ResetStone();


int main()
{
	int end =Rule();
	if (end == 0) return 0;
	Play();
	return 0;
}

int Rule()
{
	int x = 30, y = 5;
	char press;
	goxy(x, y);
	printf(" 오목 룰 설명 \n");
	x = 20, y = 7;
	goxy(x, y);
	printf("흑돌이 먼저 수를 둡니다.\n");
	y = 9;
	printf("흑돌은 3x3, 4x4 수를 둘 수 없습니다.\n");
	y = 11;
	goxy(x, y);
	printf("돌이 5개 이상 연결되면 승리합니다.\n");
	y = 13;
	goxy(x, y);
	printf("게임을 시작하시려면 Space Bar를 누르세요\n");
	y = 15;
	goxy(x, y);
	printf("게임을 종료하시려면 ESC를 눌러주세요\n");
	goxy(20, 19);
	for (;;)
	{
		press = _getch();
		if (press == 27)
			return 0;
		if (press == 32)
		{
			goxy(x, y);
			system("cls"); //clean screen
			return 1;
		}
	}

}
void Play()
{
	int i,j;
    for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
		{
			goBoard[i][j] = 20;
		} //바둑판 2차원 배열 10층 각 10호에 0을 넣었다.
	goxy(50, 5);
	printf("흑돌 차례입니다.");
	goxy(0, 0);
	Paint_Board();//바둑판 그리기
	int x=18, y=8;
	goxy(x, y);
	Define_Stone();//돌의 색 정의

	char key;
	do
	{
		key = _getch();
		ResetStone(x,y);
		Action(key, &x, &y);




		Define_Stone();
	} while (key != 27);
}

void Paint_Board()
{
	int i, j;
	printf("┌ ");//좌표 신경 안쓰고 그냥 그리는 것
	for (i = 0; i < 17; i++)
		printf("┬ ");
	printf("┐\n");
	for (i = 0; i < 17; i++)
	{
		printf("├ ");
		for (j = 0; j < 17; j++)
			printf("┼ ");
		printf("┤\n");
	}
	printf("└ ");
	for (i = 0; i < 17; i++)printf("┴ ");
	printf("┘");
}
void Define_Stone() //칼라에 따라 돌의 색 정의
{
	if (Color == 1)
		printf("●");
	else
		printf("○");
}
void ResetStone(int x, int y) //커서에 무엇인가 입력되면 워래 위치 x,y 자리에
{                             //바둑판을 메워넣으면서 복원
	if (x == 0 && y == 0)
		printf("┌");
	else if (x == 36 && y == 0)
		printf("┐");
	else if (x == 0&& y ==18)
		printf("└");
	else if(x ==36 && y ==18)
		printf("┘");
	else if (x == 0)
		printf("├");
	else if(y == 0)
		printf("┬");
	else if(x == 36)
		printf("┤");
	else if(y ==18)
		printf("┴");
	else
		printf("┼");
}
void Action(char key,int*x, int*y)
{
	//이동하기 엔 좌표이동해주고 +  스페이스바 시엔 칼라설정 변경
	switch (key)
	{
	case :



	default:
		break;
	}


}


void goxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}