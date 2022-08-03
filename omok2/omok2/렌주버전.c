// 오목 프로그램에 도전 1016년 12월 2일 08시 45분
// 처음 목표는 화면에 바둑판을 그리고
// 원하는 위치에 바둑알을 그려 넣는다.
// 게임이 진행되는 동안 승패 여부를 검사한다.
// 모든 룰은 무시하고
// 5줄 연속으로 돌이 놓이면 승리로 간주한다.
// 승패가 갈리면 게임을 종료하고
// "흑"이 또는 "백"이 승리 하였다고 알린다.
// 한번더 할 것인지 물어본다.

// 착수할 때 실수할 수 있으니
// 한번의 무르기를 인정한다.

// 마지막 착수 지점을 빈공간에 좌표로 표시해준다.


// 1단계 console game을 만들기 위한 기본 Data를 복사해온다.
// 이 부분은 굳이 이해하려거나 외울 필요는 없다.
// 필요할 때마다 복사해 가져다 쓰면 된다.

/* 게임 프로그램을 만들 때 유용하게 사용하는 함수와 키보드 색생표 */

//-----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define BACK_SPACE       8
#define	ENTER   		13
#define	ESC				27
#define UP				72
#define DOWN			80
#define LEFT			75
#define RIGHT			77
#define PAGE_UP			73
#define PAGE_DOWN		81
#define DEL	    		83

enum {
	BLACK,			/*  0 : 까망 */
	DARK_BLUE,		/*  1 : 어두운 파랑 */
	DARK_GREEN,		/*  2 : 어두운 초록 */
	DARK_SKY_BLUE,	/*  3 : 어두운 하늘 */
	DARK_RED,		/*  4 : 어두운 빨강 */
	DARK_VIOLET,	/*  5 : 어두운 보라 */
	DARK_YELLOW,	/*  6 : 어두운 노랑 */
	GRAY,			/*  7 : 회색 */
	DARK_GRAY,		/*  8 : 어두운 회색 */
	BLUE,			/*  9 : 파랑 */
	GREEN,			/* 10 : 초록 */
	SKY_BLUE,		/* 11 : 하늘 */
	RED,			/* 12 : 빨강 */
	VIOLET,			/* 13 : 보라 */
	YELLOW,			/* 14 : 노랑 */
	WHITE,			/* 15 : 하양 */
};

//--------------------------------------------------- draw class

// 바둑판의 크기를 매크로로 정의 하자
// 바둑판의 크기는 19 X 19이지만
// 오목판의 경우 15 X 15라 한다.
// x와 y의 크기가 같으니 하나만 정의
#define SIZE       15
#define CENTER     ((SIZE + 2) / 2)
#define FINISH    -1
#define TIED       2

// 바둑판은 배경은 녹색, 줄은 검은 색으로 한다.
// 바둑돌은 흰색과 검은색으로 한다.
enum { BLACK_STONE, WHITE_STONE, CURSOR, BLACKWIN, WHITEWIN, TIE, LINE };
enum { OCCUPIED = 10, SAMSAM, SASA, SIXMOK, NOTUNDO, FIVEMOK, CHANGE, PASS };
enum { HIDE, SHOW };

// 화면을 그려줄 Draw class를 만든다.
// 이 class도 이전 사용하였던 걸 수정하여 재 사용한다.
class CDRAW
{
private:
	CDRAW();
	~CDRAW() { ; }
	// 게임보드의 좌상단 위치
	int nX, nY;

public:
	static CDRAW* getInstance();
	int    getLineNumber(int x, int y);
	int    GetMenu(char* cTitle);
	void   printData(int& x, int& y, int type);
	void   printNum();
	void   drawTime(time_t sec);
	void   showMsg(int msg);
	void   errMsg(int msg);
	bool   endMsg(int stone);
	void   CursorView(char show);
	void   gotoxy(int x, int y);
	void   SetColor(int color);
	void   SetColor(int color, int bgcolor);
	void   infoKey();
	void   Notify(int type);
};
// singleton으로 사용하기 위한 매크로
#define pDraw CDRAW::getInstance

CDRAW* CDRAW::getInstance()
{
	static CDRAW draw;
	return &draw;
}

CDRAW::CDRAW()
{
	nX = (40 - SIZE - 1) / 2;
	nY = 11 - SIZE / 2;
}

/* ========================================================================== */
/* 화면의 커서를 보이거나 숨기기 */
void CDRAW::CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

/* ========================================================================== */
/* x, y 좌표로 커서를 움직이는 함수 */
void CDRAW::gotoxy(int x, int y) /*커서이동 함수 부분*/
{
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

/* ========================================================================== */
/* 콘솔 색깔을 지정하는 함수 */
void CDRAW::SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* ========================================================================== */
/* 콘솔 바탕과 글자에 색깔을 지정하는 함수 */
void CDRAW::SetColor(int color, int bgcolor)
{

	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void CDRAW::Notify(int type)
{
	const char* cNotify[] = {
		" ",
		" ",
		"흑 백 모두 아무 제약이 없이   ",
		"둘수 있습니다.       ",
		"흑 백 모두 33금수 적용됩니다. ",
		"                     ",
		"흑은 33, 44, 6목을 둘 수 없고,",
		"백은 제약이 없습니다."
	};

	SetColor(GRAY);
	gotoxy(nX * 2, nY - 2);
	printf("%s", cNotify[type * 2]);
	gotoxy(nX * 2, nY - 1);
	printf("%s", cNotify[type * 2 + 1]);
}

int CDRAW::GetMenu(char* cTitle)
{
	int x, y, n;

	const char* strTitle[] = {
		"O M O K  G A M E",
		"고모쿠(GOMOKU) 룰",
		"일반룰(NORMAL) 룰",
		"렌  주(RENJU)  룰",
		"그   만   하   기"
	};

	const char* menu[] = { "    ",
						   "                         ",
						   "  1. ",
						   "                         ",
						   "  2. ",
						   "                         ",
						   "  3. ",
						   "                         ",
						   "  4. " };

	x = strlen(menu[1]);
	y = sizeof(menu) / sizeof(menu[0]);

	x = 40 - x / 2;
	y = 12 - y / 2 - 1;

	system("cls");
	SetColor(GRAY);
	for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++)
	{
		gotoxy(x, y + i);
		if (i & 1) printf("%s", menu[i]);
		else printf("%s%s", menu[i], strTitle[i / 2]);
	}

	while (true)
	{
		n = getch();
		if (n == ESC || n == '4') return ESC;
		else if (n >= '1' && n <= '3') break;
	}

	n -= '0';
	sprintf(cTitle, "OMOK GAME - %s", strTitle[n]);
	return n;
}

// 각종 메시지를 화면에 출력해준다. 
void CDRAW::errMsg(int msg)
{
	msg -= 10;
	const char* str[] = {
		"이미 돌이 놓여 있습니다.\n다른 곳에 착점하세요.",
		"삼삼 입니다.\n다른 곳에 착점하세요.",
		"사사 입니다.\n다른 곳에 착점하세요.",
		"흑은 육목을 둘 수 없습니다.\n다른 곳에 착점하세요.",
		"한 수만 물릴 수 있습니다"
	};
	MessageBox(NULL, str[msg], "Warning!", MB_OK);
}

void CDRAW::showMsg(int msg)
{
	const char* str[] = {
		"흑이 둘 차례입니다.",
		"백이 둘 차례입니다.",
		"       ",
		"흑 승입니다.       ",
		"백 승입니다.       ",
		"무승부입니다.      ",
	};

	SetColor(GRAY);
	gotoxy((nX + SIZE + 1) * 2, nY);
	printf("%s", str[msg]);
}

void CDRAW::infoKey()
{
	const char* str[] = {
		"스페이스바 : 착  수",
		"방  향  키 : 이  동",
		"    U      : Undo  ",
		"    R      : Redo  ",
		"Delete Key : Pass  ",
		" ",
		"흑과 백이 연속으로",
		"PASS하면 무승부"
	};

	SetColor(GRAY);
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		gotoxy((nX + SIZE + 1) * 2, nY + 4 + i);
		printf(str[i]);
	}
}

// 승패가 갈리면 승자를 알리고
// 한번더 할 것인지 물어본다.
bool CDRAW::endMsg(int stone)
{
	const char* winner[] = { "    흑 승입니다.\n    한 게임 더 하시겠습니까?     ",
							"    백 승입니다.\n    한 게임 더 하시겠습니까?     ",
							"    무승부입니다.\n    한 게임 더 하시겠습니까?     " };
	showMsg(stone + 3);
	if (MessageBox(NULL, winner[stone], "알 림", MB_YESNO) == IDYES) return true;
	else return false;
}

// 바둑판과 돌을 그린다.
void CDRAW::printData(int& x, int& y, int type)
{
	if (x < 1)          x = 1;
	else if (y < 1)     y = 1;
	else if (x > SIZE)  x = SIZE;
	else if (y > SIZE)  y = SIZE;

	const int color[] = { BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK };
	const char* shape[] = { "┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘", "●", "●", "□" };

	SetColor(color[type], DARK_YELLOW);
	// 라인의 종류는 9가지 모양을 가지니까
	// 어떤걸 그려야 할지 좌표를 주고 모양을 가져온다.
	if (type == LINE) type = getLineNumber(x, y);
	// 라인은 0-8까지 이고, 그 뒤에 돌이 배치되어 있으니 9를 더해준다.
	else type += 9;
	gotoxy((x + nX - 1) * 2, y + nY - 1);
	printf("%s", shape[type]);
	SetColor(GRAY);
}

// 가로와 세로줄의 좌표를 숫자와 알파벳으로 표시해준다.
// 가로나 세로에 숫자나 아파벳으로 통일하면 좌표를 표시할 때
// 혼동이 올 수 있으니 구분해 표시한다.
void CDRAW::printNum()
{
	SetColor(BLACK, DARK_YELLOW);
	//x방향 출력
	for (int i = 0; i < SIZE; i++)
	{
		gotoxy((nX + i) * 2, nY + SIZE);
		printf("%2c", i + 'A');
	}
	//y방향 출력
	for (int i = 0, j = SIZE; i < SIZE; i++, j--)
	{
		gotoxy((nX - 1) * 2, nY + j - 1);
		printf("%2d", i + 1);
	}
	gotoxy((nX - 1) * 2, nY + SIZE);
	printf("  ");
	SetColor(GRAY);
}

//┌┬┐
//├┼┤
//└┴┘
//순서는 아래와 같이 한다.
//0 1 2
//┌┬┐
//3 4 5
//├┼┤
//6 7 8
//└┴┘
// 위 모양은 바둑판의 축소판이다
// 바둑판의 모든 모양은
// 이 9가지 모양만 있으면 그려낼 수 있다.
// x가 0일때는 왼쪽 줄
// y가 0일때는 윗쪽 행등등
// x,y값에 따라 모양의 번호를 반환한다.

// 바둑판 전체를 그려넣고 다시 그려도 되지만
// 그렇게 하면 만약 Size를 19로 하고 싶을때
// 전체를 수정해야 되고, 또한 화면이 깜빡 거릴 수 있어서
// 필요한 곳만 그때그때 그려주려 이런 작업을 한는 것이다.
int CDRAW::getLineNumber(int x, int y)
{
	// 왼쪽 세로줄
	if (x == 1)
	{
		// x, y가 다 0이면 왼쪽 상단 모서리
		if (y == 1) return 0;
		// 왼쪽 하단 모서리
		else if (y == SIZE) return 6;
		// 왼쪽 세로줄
		else return 3;
	}
	// 오른쪽 세로줄
	else if (x == SIZE)
	{
		// 오른쪽 상단 모서리
		if (y == 1) return 2;
		// 오른쪽 하단 모서리
		else if (y == SIZE) return 8;
		// 오른쪽 세로줄
		else return 5;
	}
	// 윗쪽 가로줄
	else if (y == 1) return 1;
	// 아래쪽 가로줄
	else if (y == SIZE) return 7;
	// 마지막 가운데 + 모양
	else return 4;
}

//게임 시간을 화면에 표시해준다.
void CDRAW::drawTime(time_t sec)
{
	int hh, mm;

	hh = sec / 3600;
	mm = (sec % 3600) / 60;
	sec = sec %= 60;

	SetColor(SKY_BLUE);
	gotoxy(nX * 2 - 2, nY + SIZE + 1);
	printf("%02d : %02d : %02d", hh, mm, sec);
	SetColor(GRAY);
}

//----------------------------------------------------------------------------------- Omokrule class
// openSource의 명료하고 깔끔한  작명과 구성을
// 제가 만들었던 압축된 알고리즘을 합성하여
// 새롭게 Omokrule class를 만들어 오목 프로그램에 적용해본다.

class COMOKRULE
{
private:
	int    nBoard[SIZE + 2][SIZE + 2];

public:
	COMOKRULE();
	virtual ~COMOKRULE() { ; }

	void SetBoard(int(*arr)[SIZE + 2]);
	bool IsFive(int x, int y, int nStone);
	bool IsSix(int x, int y, int nStone);
	bool IsFour(int x, int y, int nStone, int nDir);
	int  IsOpenFour(int x, int y, int nStone, int nDir);
	bool IsOpenThree(int x, int y, int nStone, int nDir);
	bool IsDoubleFour(int x, int y, int nStone);
	bool IsDoubleThree(int x, int y, int nStone);

private:
	void SetStone(int x, int y, int nStone);
	void GetDirTable(int& x, int& y, int i);
	bool IsFive(int x, int y, int nStone, int nDir);
	bool IsEmpty(int& x, int& y, int nStone, int i);
	bool IsForbidden(int x, int y, int nStone);
	int  GetStoneCount(int x, int y, int nStone, int nDir);
};

COMOKRULE::COMOKRULE()
{
	for (int i = 0; i < SIZE + 2; i++)
	{
		//바둑판 밖의 배열의 끝을 LINE이나 STONE이 아닌 
		//다른 숫자로 셋팅함으로써 경계임을 나타낸다. 
		nBoard[i][0] = nBoard[i][SIZE + 1] = -1;
		nBoard[0][i] = nBoard[SIZE + 1][i] = -1;
	}
}

// 착수하기 전의 바둑판 상태를 복사한다. 
void COMOKRULE::SetBoard(int(*arr)[SIZE + 2])
{
	for (int i = 1; i <= SIZE; i++)
		for (int j = 1; j <= SIZE; j++)
			nBoard[i][j] = arr[i][j];
}

// x, y좌표에 돌을 놓거나 들어낸다.
// 들어낸다는 말은 그곳에  Line을 다시 그려넣는 걸 의미한다. 
void COMOKRULE::SetStone(int x, int y, int nStone)
{
	nBoard[y][x] = nStone;
}

// 8개의 숫자는 8방향을 나타낸다.
// 배열의 순서대로 서, 동, 북, 남, 서북, 동남, 남서, 북동
// (동, 서) (남 북) (서북, 동남) (남서, 북동)이 한쌍이되어
// 가로 세로 양 대각선의 양쪽을 dx, dy로 표시한 Table 
void COMOKRULE::GetDirTable(int& x, int& y, int nDir)
{
	//          서  동  북  남  북서 남동 남서 북동 
	int dx[] = { -1,  1,  0,  0, -1,   1,  -1,   1 };
	int dy[] = { 0,  0, -1,  1, -1,   1,   1,  -1 };

	x = dx[nDir];
	y = dy[nDir];
}

// 주어진 방향으로 좌표를 옮겨 빈곳을 찾아 
// 그곳의 좌표를 알려준다. 
bool COMOKRULE::IsEmpty(int& x, int& y, int nStone, int nDir)
{
	int dx, dy;

	// 방향 Table에서 dx, dy값을 가져온다.
	// 만약 nDir이 0이라면 dx = -1, dy = 0이다. 
	GetDirTable(dx, dy, nDir);
	// x는 1 y는 0이니까 x += dx, y += dy 이 수식에 의해서 
	// x는 점점 작아저 왼쪽으로 가고, y는 변함이 없으니 한자리
	// 그래서 가로로 왼쪽에 nStone이 아닌 곳에서 멈추게 된다. 
	for (; nBoard[y][x] == nStone; x += dx, y += dy);

	// nStone이 아니라 해서 전부 LINE이라 할 수 없다.
	// 다른 돌이거나 바둑판을 벗어난 곳 일수도 있으니
	// 그곳이 LINE일 때만 참을 반환한다. 
	if (nBoard[y][x] == LINE) return true;
	else return false;
}

// 주어진 좌표에 한점을 착점하고,
// 주어진 방향(nDir)으로 
// 연속된 돌이 몇개인지 세어서 반환한다. 
int COMOKRULE::GetStoneCount(int x, int y, int nStone, int nDir)
{
	int dx, dy;
	int tx = x;
	int ty = y;
	int cnt = 0;

	// 착점할 곳이 Line이 아니면 착점할 수 없으니
	// 0을 return한다. 
	if (nBoard[y][x] != LINE) return 0;
	SetStone(x, y, nStone);

	// 방향 Table에서 dx, dy값을 가져와 
	GetDirTable(dx, dy, nDir);
	//착점한 곳에서부터 nDir방향으로 같은 돌의 갯수를 센다. 
	for (; nBoard[y][x] == nStone; x += dx, y += dy) cnt++;

	// 방향 Table이 하나로 되어있고, 
	// 순서는 항상 서동 또는 북남으로 되어 있어 
	// nDir이 홀수일 때는 -1한 방향을 검사하여야 한다.
	// 그렇지 않고 다음 방향이라고 무심코 +1한다면
	// 만약 nDir이 동(1)이라면 서(0)쪽을 검사해야 되는데
	// +1해서 2가 되면 서(0)가 아닌 북(2)을 검사하게 된다. 
	// 이를 방지하기 위해 3항 연산자를 이용해
	// 조건에 맞는 방향을 인수로 넘기게 하였다. 
	GetDirTable(dx, dy, nDir % 2 ? nDir - 1 : nDir + 1);

	// x, y값이 위에서 연산을 하느라 처음 좌표를 벗어났기 때문에
	// 처음 좌표값에 다음 방향으로 한칸 옮겨서 그곳에서부터
	// 돌의 갯수를 센다. 
	// 위에서 돌 놓았던 곳을 세었기에 중복을 피하기 위해서다. 
	x = tx + dx;
	y = ty + dy;
	for (; nBoard[y][x] == nStone; x += dx, y += dy) cnt++;

	// 돌의 갯수를 다 세었으면 돌을 들어낸다. 
	SetStone(tx, ty, LINE);
	return cnt;
}

// 착점을 하였을때 오목인지 검사한다. 
bool COMOKRULE::IsFive(int x, int y, int nStone)
{
	// 방향 Table의 값이 8이니까 8까지 검사하고
	// 증가분이 +=2인건
	// 아래 GetStoneCount()함수 안에서 양끝을 검사하기 때문이다. 
	for (int i = 0; i < 8; i += 2)
	{
		if (GetStoneCount(x, y, nStone, i) == 5) return true;
	}
	return false;
}

// 위와 같이 오목인지를 검사하지만,
// nDir방향에 대해서만 검사한다.
// 이는 Four나 OpenFour가 되는지 알아보기 위하여 
// 빈곳에 돌을 하나씩 놓아보면서
// 오목이 되는지 검사하기 위해서다. 
bool COMOKRULE::IsFive(int x, int y, int nStone, int nDir)
{
	if (GetStoneCount(x, y, nStone, nDir) == 5) return true;
	return false;
}

// 오목을 검사하는 것과 같이 6목 이상인지 검사한다. 
bool COMOKRULE::IsSix(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2)
	{
		if (GetStoneCount(x, y, nStone, i) >= 6) return true;
	}
	return false;
}

// 착수를 했을때 4인지를 검사한다.
bool COMOKRULE::IsFour(int x, int y, int nStone, int nDir)
{
	// 원래의 좌표 x, y를 대신하기 위한 변수
	int tx, ty;

	// 한 방향에 대하여 양끝을 검사하는데
	// 한쌍의 좌표중 첫번째부터 검사하기 위하여
	nDir % 2 ? nDir -= 1 : nDir;
	// 좌표에 착점을 한다
	SetStone(x, y, nStone);
	// 다음 양끝을 검사
	for (int i = 0; i < 2; i++)
	{
		// 원래의 좌표를 중심으로 주어진 방향(nDir)에 대하여
		// 양쪽으로 이동하면서 빈곳을 찾아 그곳의 좌표를 얻어와야 되기에
		// 원래의 좌표가 변경이 된다. 따라서 양쪽을 검사하기위하여
		// 대신할 변수가 필요하고, 매번 아래와 같이
		// 원래의 좌표를 받아서 검사가 진행되어야 한다.
		tx = x;
		ty = y;
		// 빈곳이 있으면 그 좌표를 받아온다.
		if (IsEmpty(tx, ty, nStone, nDir + i))
		{
			// 그 빈곳에서 오목이 되는지 검사한다.
			if (IsFive(tx, ty, nStone, nDir + i))
			{
				// 오목이 되었다면 4이기 때문에
				// 돌을 들어내고 참을 리턴한다.
				SetStone(x, y, LINE);
				return true;
			}
		}
	}

	// 검사를 해봤지만 4가 아니라 해도 돌을 들어낸다.
	SetStone(x, y, LINE);
	return false;
}

// 돌이 연속으로 4개이고 끝에 돌을 놓았을때 오목이 되면
// 열린4가 된다.
int COMOKRULE::IsOpenFour(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	// 열린4가 될때는 양쪽에 돌을 놓았을때
	// 양쪽 모두 오목이 되어야 되기때문에
	// 두곳다 4가 되는지 검사를 위한 변수
	int sum = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	SetStone(x, y, nStone);
	for (int i = 0; i < 2; i++)
	{
		tx = x;
		ty = y;
		// 여기까지는 Four()함수와 같다.
		if (IsEmpty(tx, ty, nStone, nDir + i))
		{
			if (IsFive(tx, ty, nStone, nDir + i)) sum++;
		}
	}
	SetStone(x, y, LINE);

	// 양쪽으로 모두가 오목이 되었을때만 열린4이다.
	if (sum == 2)
	{
		// 열린4일 때는 특이하게 한줄에 44가 될수 있다.
		// 1234567   12345678
		// 0 0 0 0   00  0 00
		// 위와 같은 상황에서 4위치에 돌이 놓이면
		// 양쪽이 모두 4가 되어 한줄에서 44가 발생한다.
		// 때문에 0000 이와같이 연속일때는 4가 하나이기 때문에
		// 검사를 하여 갯수를 정확하게 한다.
		if (GetStoneCount(x, y, nStone, nDir) == 4) sum = 1;
	}
	// sum이 2가 아니면 열린4가 아니므로 0
	else sum = 0;

	return sum;
}

bool COMOKRULE::IsDoubleFour(int x, int y, int nStone)
{
	int cnt = 0;

	//좌표를 중심으로 각각의 줄에대하여 4를 검사한다.
	for (int i = 0; i < 8; i += 2)
	{
		// OpenFour()에서는 한 줄에 44가 나올 수 있으니 검사하고
		if (IsOpenFour(x, y, nStone, i) == 2) return true;
		// 열린4도 4이니 4를 검사하여 2개 이상이면 44이다.
		else if (IsFour(x, y, nStone, i)) cnt++;

		if (cnt >= 2) return true;
	}

	return false;
}

bool COMOKRULE::IsOpenThree(int x, int y, int nStone, int nDir)
{
	int tx, ty;

	SetStone(x, y, nStone);
	for (int i = 0; i < 2; i++)
	{
		tx = x;
		ty = y;
		if (IsEmpty(tx, ty, nStone, nDir += i))
		{
			// 33은 돌을 하나 더 놓았을 때 반드시 열린4이어야 되고,
			// 한 점 놓을 자리가 44, 6목, 또다른 33
			// 즉 금수자리가 아니어야 된다.
			if ((IsOpenFour(tx, ty, nStone, nDir) == 1) && (!IsForbidden(tx, ty, nStone)))
			{
				// 위 조건을 만족하는 자리이면 3이므로 돌을 제거하고 참을 리턴한다.
				SetStone(x, y, LINE);
				return true;
			}
		}
	}

	SetStone(x, y, LINE);
	return false;
}

// 33을 검사한다.
bool COMOKRULE::IsDoubleThree(int x, int y, int nStone)
{
	int cnt = 0;

	for (int i = 0; i < 8; i += 2)
	{
		if (IsOpenThree(x, y, nStone, i)) cnt++;
		if (cnt >= 2) return true;
	}

	return false;
}

// 금수자리를 검사한다.
bool COMOKRULE::IsForbidden(int x, int y, int nStone)
{
	if (IsDoubleFour(x, y, nStone)) return true;
	else if (IsDoubleThree(x, y, nStone)) return true;
	else if (IsSix(x, y, nStone)) return true;
	else return false;
}

//------------------------------------------------------------------------ Omok class
struct UndoInfo
{
	int x, y;
	int nStone;
};

class COMOK
{
protected:
	static int  arrBoard[SIZE + 2][SIZE + 2];
	static int  x, y;

	// Undo와 Redo를 위한 top pointer 
	static int  uTop, rTop;
	// last 착수점 
	static int  lx, ly;

	// 커서의 깜박임을 구현하기 위한 시간
	static time_t t1, t2;

	static UndoInfo uInfo[SIZE * SIZE];
	static UndoInfo rInfo[SIZE * SIZE];

	COMOKRULE orule;

	bool    isOccupy();
	bool    checkSamSam();
	void    undoSet(int nStone);
	void    drawBoard();
	void    saveBoard(int stone);
	void    setXY(int ax, int ay);

public:
	COMOK();
	virtual ~COMOK() { ; }

	void setBoard(int x, int y);
	void cursorView(int x, int y);
	void initOmok();
	void initBoard();
	int  undo();
	int  redo();

	virtual int placement(int ax, int ay, int stone);
};

class CBLACKSTONE : public COMOK
{
private:

public:
	CBLACKSTONE();
	~CBLACKSTONE() { ; }

	virtual int placement(int ax, int ay, int stone);
};

class CNORMAL : public COMOK
{
private:

public:
	CNORMAL();
	~CNORMAL() { ; }

	virtual int placement(int ax, int ay, int stone);
};
int      COMOK::arrBoard[SIZE + 2][SIZE + 2] = { LINE, };
int      COMOK::lx = 0;
int      COMOK::ly = 0;
int      COMOK::x = CENTER;
int      COMOK::y = CENTER;
time_t   COMOK::t1 = clock() - 500;
time_t   COMOK::t2 = clock();
UndoInfo COMOK::uInfo[SIZE * SIZE] = { 0 };
UndoInfo COMOK::rInfo[SIZE * SIZE] = { 0 };
int      COMOK::uTop = -1;
int      COMOK::rTop = -1;

COMOK::COMOK()
{
	x = y = CENTER;
	undoSet(BLACK_STONE);
}

//바둑이 시작될 때 초기화 
void COMOK::initOmok()
{
	drawBoard();
	initBoard();
	t2 = clock();
	// 1초에 한번씩 그리는데 시차를 두기 위해서
	// 결과적으로 500msec마다 커서처럼 깜박거리게 된다. 
	t1 = clock() - 500;
	pDraw()->infoKey();
	uTop = rTop = -1;
}

//커서를 이동하기전 원래 바둑판을 복원한다. 
void COMOK::setBoard(int x, int y)
{
	pDraw()->printData(x, y, arrBoard[y][x]);
	// 커서가 이동중일땐 커서가 깜박잊 않게 한다.
	// 멈췄을때 얼마 지나지 않아 깜박이도록 시간 조절  
	t2 = clock() - 400;
	t1 = clock() - 900;
}

// 커서를 대신해 커서처럼 보이게 한다.
void COMOK::cursorView(int x, int y)
{
	// 커서를 1초단위로 그려준다. 
	if (clock() - t1 >= 1000)
	{
		pDraw()->printData(x, y, CURSOR);
		t1 = clock();
	}
	// 커서 위치의 바둑판을 1초 단위로 그려준다. 
	if (clock() - t2 >= 1000)
	{
		pDraw()->printData(x, y, arrBoard[y][x]);
		t2 = clock();
	}
}

int COMOK::undo()
{
	if (uTop < 0) return false;

	rInfo[++rTop].x = lx = uInfo[uTop].x;
	rInfo[rTop].y = ly = uInfo[uTop].y;
	rInfo[rTop].nStone = uInfo[uTop--].nStone;

	pDraw()->printData(lx, ly, LINE);
	arrBoard[ly][lx] = LINE;

	return CHANGE;
}

int COMOK::redo()
{
	if (rTop < 0) return false;

	uInfo[++uTop].x = lx = rInfo[rTop].x;
	uInfo[uTop].y = ly = rInfo[rTop].y;
	uInfo[uTop].nStone = rInfo[rTop--].nStone;

	pDraw()->printData(lx, ly, uInfo[uTop].nStone);
	arrBoard[ly][lx] = uInfo[uTop].nStone;

	return CHANGE;
}

void COMOK::undoSet(int nStone)
{
	uInfo[++uTop].x = x;
	uInfo[uTop].y = y;
	uInfo[uTop].nStone = nStone;
	rTop = -1;
}

// 바둑판을 그린다. 
void COMOK::drawBoard()
{
	pDraw()->printNum();
	for (int i = 1; i <= SIZE; i++)
		for (int j = 1; j <= SIZE; j++)
			pDraw()->printData(j, i, LINE);
}

// 돌이 놓이면 배열에 흑백돌을 저장한다.
// 처음 흑돌을 중앙에 한수 놓고 시작한다. 
void COMOK::initBoard()
{
	for (int i = 0; i < SIZE + 2; i++)
		for (int j = 0; j <= SIZE + 2; j++)
			arrBoard[i][j] = LINE;
	arrBoard[CENTER][CENTER] = BLACK_STONE;
}

// 바둑알 놓을 자리를 체크한다. 
bool COMOK::isOccupy()
{
	return arrBoard[y][x] != LINE;
}

// 바둑알이 착점 되면 보드에 바둑알을 그리고
// 보드 배열에 저장한다.  
void COMOK::saveBoard(int stone)
{
	pDraw()->printData(x, y, stone);
	arrBoard[y][x] = stone;
	undoSet(stone);
}

// Game class에서 받아온 좌표를 저장한다.
void COMOK::setXY(int ax, int ay)
{
	x = ax;
	y = ay;
}

// 착점을 위한함수
// 착점이 가능한지 체크하고
// 착점이 되면 저장을 한다.
// 다음으로 오목인지 검사하여 결과를 리턴한다.
int COMOK::placement(int ax, int ay, int nStone)
{
	setXY(ax, ay);
	if (isOccupy()) return OCCUPIED;

	int returnValue = CHANGE;
	orule.SetBoard(arrBoard);
	if (orule.IsFive(x, y, nStone) || orule.IsSix(x, y, nStone)) returnValue = FIVEMOK;
	saveBoard(nStone);

	return returnValue;
}

//------------------------------------------------------- blackstone class
// Renju rule은 검은돌만 적용 되기때문에 별도의 class로 분리하였다.
CBLACKSTONE::CBLACKSTONE()
{
}

int CBLACKSTONE::placement(int ax, int ay, int nStone)
{

	setXY(ax, ay);
	if (isOccupy()) return OCCUPIED;

	orule.SetBoard(arrBoard);
	if (orule.IsFive(x, y, nStone))
	{
		saveBoard(nStone);
		return FIVEMOK;
	}
	else if (orule.IsSix(x, y, nStone)) return SIXMOK;
	else if (orule.IsDoubleFour(x, y, nStone))  return SASA;
	else if (orule.IsDoubleThree(x, y, nStone)) return SAMSAM;

	saveBoard(nStone);
	return CHANGE;
}

CNORMAL::CNORMAL()
{
}

int CNORMAL::placement(int ax, int ay, int nStone)
{
	setXY(ax, ay);
	if (isOccupy()) return OCCUPIED;

	orule.SetBoard(arrBoard);
	if (orule.IsFive(x, y, nStone))
	{
		saveBoard(nStone);
		return FIVEMOK;
	}
	else if (orule.IsDoubleThree(x, y, nStone)) return SAMSAM;

	saveBoard(nStone);
	return CHANGE;
}

//----------------------------------------------------omokfactory class
class COMOKFACTORY
{
private:
	COMOK       gomoku_Black;
	COMOK       gomoku_White;
	CNORMAL     general_Black;
	CNORMAL     general_White;
	CBLACKSTONE renju_Black;

public:
	COMOKFACTORY() {}
	~COMOKFACTORY() {}

	COMOK* GetInstance(int type);
};

COMOK* COMOKFACTORY::GetInstance(int type)
{
	switch (type)
	{
	case 10: return &gomoku_Black;

		// 렌주룰에서 백은 고모쿠 룰처럼 
		// 모든 금수가 허용되므로 같이 쓰면 된다. 
	case 31:
	case 11: return &gomoku_White;
	case 20: return &general_Black;
	case 21: return &general_White;
	case 30: return &renju_Black;
	}
}

//----------------------------------------------------------- Game class
// Game진행을 전담하는 class
class CGAME
{
private:
	// t1 : 1초마다 화면에 시간을 표시해주기 위한 변수
	// 매초마다 초기화
	// t2 : 게임이 시작 될때 초기화 하여
	// 게임이 종료될 때까지 유지하면서 기준시간이 된다.
	// t3 : 시간제한이 필요할때 사용할 변수
	time_t  t1, t2, t3;
	//현재 착점을 할 돌
	int     curStone;
	// omok의 x, y와 같은 좌표를 유지한다.
	int     x, y;

	// 무승부를 알기 위해서 변수가 이렇게 많이 필요하다.
	// 누군가 pass를  하면 passTrigger가 On상태가 된다.
	// 그럼 passCounter가 시작되고
	// 연속으로 백돌과 흑돌이 연속으로 눌렀는지
	// 아니면 한쪽 돌만 연속으로 pass한 것인지
	// 판단하기 위하여 stoneState는 배열을 사용함.
	// 무승부임을 알리는게 의외로 복잡하다.
	bool    passTriggerOn;
	int     passCount;
	int     stoneState[2];

	COMOKFACTORY factory;
	COMOK* pOmok[2];

	bool        checkTie();
	void        drawTime();
	void        initGame();
	void        changeStone();
	int         getKey();
	int         checkKey();

public:
	CGAME();
	~CGAME() { ; }

	bool    playGame(int type);
};

CGAME::CGAME()
{
}

// 게임이 시작할때 필요한 변수들을 초기화 하고,
// 화면에 표시해준다. 
void CGAME::initGame()
{
	x = y = CENTER;
	t1 = t2 = clock();
	passTriggerOn = false;
	passCount = 0;
	stoneState[0] = 0;
	stoneState[1] = 0;
	drawTime();
	curStone = WHITE_STONE;
	pDraw()->printData(x, y, BLACK_STONE);
	pDraw()->showMsg(curStone);
	pOmok[curStone]->initOmok();
	pOmok[curStone]->cursorView(x, y);
}

// main함수에서 이 함수를 호출하면 게임이 시작된다. 
bool CGAME::playGame(int type)
{
	int result;
	system("cls");

	pOmok[0] = factory.GetInstance(type * 10 + 0);
	pOmok[1] = factory.GetInstance(type * 10 + 1);
	pDraw()->Notify(type);
	initGame();
	while (true)
	{
		// 1초마다 화면에 시간을 표시한다. 
		if (clock() - t1 >= 1000) drawTime();

		result = checkKey();
		switch (result)
		{
			// 키보드로부터 ESC키가 눌리면 게임을 종료한다. 
		case FINISH: return false;
			// 오목이 되었으면 승자를 알리고, 계속할건지 물어본다. 
		case FIVEMOK: return pDraw()->endMsg(curStone);
			// 착수가 불가능한 곳은 그 이유를 알린다. 
		case OCCUPIED:
		case SAMSAM:
		case SASA:
		case SIXMOK:
		case NOTUNDO:
			pDraw()->errMsg(result);
			pOmok[curStone]->setBoard(x, y);
			break;
			//착수가 됐거나, 한수 물렸을 때 돌을 바꾼다.  
		case PASS: if (!passTriggerOn) passTriggerOn = true;
			stoneState[curStone]++;
		case CHANGE: changeStone(); break;
		default: break;
		}
		pOmok[curStone]->cursorView(x, y);
		if (checkTie()) return pDraw()->endMsg(TIED);
		Sleep(20);
	}
}

// 흑과 백의 둘 차례를 바꾼다. 
void CGAME::changeStone()
{
	// 흑백 둘이니 더해서 2로 나누면 교환이 된다. 
	curStone = (curStone + 1) % 2;
	// 현재 둘 차례를 알려준다. 
	pDraw()->showMsg(curStone);
	if (passTriggerOn) passCount++;
}

bool CGAME::checkTie()
{
	if (!passTriggerOn) return false;

	bool isTied = false;
	if (passCount == 2)
	{
		if (stoneState[0] == 1 && stoneState[1] == 1) isTied = true;
		passTriggerOn = false;
		passCount = 0;
		stoneState[0] = 0;
		stoneState[1] = 0;
	}
	return isTied;
}

// 1 초마다 화면에 시간을 표시한다. 
void CGAME::drawTime()
{
	time_t sec = (clock() - t2) / 1000;
	pDraw()->drawTime(sec);
	t1 = clock();
}


int CGAME::getKey()
{
	int ch = getch();
	if (ch == 0 || ch == 0xE0) ch = getch();

	return ch;
}

int CGAME::checkKey()
{
	int ch, dx, dy;;

	if (kbhit()) ch = getKey();
	else return 0;

	dx = dy = 0;
	switch (ch)
	{
	case UP: --dy; break;
	case DOWN: ++dy; break;
	case LEFT: --dx; break;
	case RIGHT: ++dx; break;

	case DEL: return PASS;
	case ESC: return FINISH;
	case ' ': return pOmok[curStone]->placement(x, y, curStone);
	case 'r':
	case 'R': return pOmok[curStone]->redo();
	case 'u':
	case 'U': return pOmok[curStone]->undo();
	default: break;
	}
	pOmok[curStone]->setBoard(x, y);
	y += dy;
	x += dx;
	pDraw()->printData(x, y, CURSOR);

	return 0;
}

int main()
{
	int type = 1;
	char cTitle[256];
	CGAME game;

	pDraw()->CursorView(HIDE);
	while (true)
	{
		SetConsoleTitle("OMOK GAME - Made by LJW");
		type = pDraw()->GetMenu(cTitle);
		if (type == ESC) break;
		else SetConsoleTitle(cTitle);

		while (game.playGame(type));
	}

	pDraw()->CursorView(SHOW);
	return 0;
}

