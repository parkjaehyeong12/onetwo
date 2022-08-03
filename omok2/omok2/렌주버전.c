// ���� ���α׷��� ���� 1016�� 12�� 2�� 08�� 45��
// ó�� ��ǥ�� ȭ�鿡 �ٵ����� �׸���
// ���ϴ� ��ġ�� �ٵϾ��� �׷� �ִ´�.
// ������ ����Ǵ� ���� ���� ���θ� �˻��Ѵ�.
// ��� ���� �����ϰ�
// 5�� �������� ���� ���̸� �¸��� �����Ѵ�.
// ���а� ������ ������ �����ϰ�
// "��"�� �Ǵ� "��"�� �¸� �Ͽ��ٰ� �˸���.
// �ѹ��� �� ������ �����.

// ������ �� �Ǽ��� �� ������
// �ѹ��� �����⸦ �����Ѵ�.

// ������ ���� ������ ������� ��ǥ�� ǥ�����ش�.


// 1�ܰ� console game�� ����� ���� �⺻ Data�� �����ؿ´�.
// �� �κ��� ���� �����Ϸ��ų� �ܿ� �ʿ�� ����.
// �ʿ��� ������ ������ ������ ���� �ȴ�.

/* ���� ���α׷��� ���� �� �����ϰ� ����ϴ� �Լ��� Ű���� ����ǥ */

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
	BLACK,			/*  0 : ��� */
	DARK_BLUE,		/*  1 : ��ο� �Ķ� */
	DARK_GREEN,		/*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,	/*  3 : ��ο� �ϴ� */
	DARK_RED,		/*  4 : ��ο� ���� */
	DARK_VIOLET,	/*  5 : ��ο� ���� */
	DARK_YELLOW,	/*  6 : ��ο� ��� */
	GRAY,			/*  7 : ȸ�� */
	DARK_GRAY,		/*  8 : ��ο� ȸ�� */
	BLUE,			/*  9 : �Ķ� */
	GREEN,			/* 10 : �ʷ� */
	SKY_BLUE,		/* 11 : �ϴ� */
	RED,			/* 12 : ���� */
	VIOLET,			/* 13 : ���� */
	YELLOW,			/* 14 : ��� */
	WHITE,			/* 15 : �Ͼ� */
};

//--------------------------------------------------- draw class

// �ٵ����� ũ�⸦ ��ũ�η� ���� ����
// �ٵ����� ũ��� 19 X 19������
// �������� ��� 15 X 15�� �Ѵ�.
// x�� y�� ũ�Ⱑ ������ �ϳ��� ����
#define SIZE       15
#define CENTER     ((SIZE + 2) / 2)
#define FINISH    -1
#define TIED       2

// �ٵ����� ����� ���, ���� ���� ������ �Ѵ�.
// �ٵϵ��� ����� ���������� �Ѵ�.
enum { BLACK_STONE, WHITE_STONE, CURSOR, BLACKWIN, WHITEWIN, TIE, LINE };
enum { OCCUPIED = 10, SAMSAM, SASA, SIXMOK, NOTUNDO, FIVEMOK, CHANGE, PASS };
enum { HIDE, SHOW };

// ȭ���� �׷��� Draw class�� �����.
// �� class�� ���� ����Ͽ��� �� �����Ͽ� �� ����Ѵ�.
class CDRAW
{
private:
	CDRAW();
	~CDRAW() { ; }
	// ���Ӻ����� �»�� ��ġ
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
// singleton���� ����ϱ� ���� ��ũ��
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
/* ȭ���� Ŀ���� ���̰ų� ����� */
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
/* x, y ��ǥ�� Ŀ���� �����̴� �Լ� */
void CDRAW::gotoxy(int x, int y) /*Ŀ���̵� �Լ� �κ�*/
{
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

/* ========================================================================== */
/* �ܼ� ������ �����ϴ� �Լ� */
void CDRAW::SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* ========================================================================== */
/* �ܼ� ������ ���ڿ� ������ �����ϴ� �Լ� */
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
		"�� �� ��� �ƹ� ������ ����   ",
		"�Ѽ� �ֽ��ϴ�.       ",
		"�� �� ��� 33�ݼ� ����˴ϴ�. ",
		"                     ",
		"���� 33, 44, 6���� �� �� ����,",
		"���� ������ �����ϴ�."
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
		"�����(GOMOKU) ��",
		"�Ϲݷ�(NORMAL) ��",
		"��  ��(RENJU)  ��",
		"��   ��   ��   ��"
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

// ���� �޽����� ȭ�鿡 ������ش�. 
void CDRAW::errMsg(int msg)
{
	msg -= 10;
	const char* str[] = {
		"�̹� ���� ���� �ֽ��ϴ�.\n�ٸ� ���� �����ϼ���.",
		"��� �Դϴ�.\n�ٸ� ���� �����ϼ���.",
		"��� �Դϴ�.\n�ٸ� ���� �����ϼ���.",
		"���� ������ �� �� �����ϴ�.\n�ٸ� ���� �����ϼ���.",
		"�� ���� ���� �� �ֽ��ϴ�"
	};
	MessageBox(NULL, str[msg], "Warning!", MB_OK);
}

void CDRAW::showMsg(int msg)
{
	const char* str[] = {
		"���� �� �����Դϴ�.",
		"���� �� �����Դϴ�.",
		"       ",
		"�� ���Դϴ�.       ",
		"�� ���Դϴ�.       ",
		"���º��Դϴ�.      ",
	};

	SetColor(GRAY);
	gotoxy((nX + SIZE + 1) * 2, nY);
	printf("%s", str[msg]);
}

void CDRAW::infoKey()
{
	const char* str[] = {
		"�����̽��� : ��  ��",
		"��  ��  Ű : ��  ��",
		"    U      : Undo  ",
		"    R      : Redo  ",
		"Delete Key : Pass  ",
		" ",
		"��� ���� ��������",
		"PASS�ϸ� ���º�"
	};

	SetColor(GRAY);
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		gotoxy((nX + SIZE + 1) * 2, nY + 4 + i);
		printf(str[i]);
	}
}

// ���а� ������ ���ڸ� �˸���
// �ѹ��� �� ������ �����.
bool CDRAW::endMsg(int stone)
{
	const char* winner[] = { "    �� ���Դϴ�.\n    �� ���� �� �Ͻðڽ��ϱ�?     ",
							"    �� ���Դϴ�.\n    �� ���� �� �Ͻðڽ��ϱ�?     ",
							"    ���º��Դϴ�.\n    �� ���� �� �Ͻðڽ��ϱ�?     " };
	showMsg(stone + 3);
	if (MessageBox(NULL, winner[stone], "�� ��", MB_YESNO) == IDYES) return true;
	else return false;
}

// �ٵ��ǰ� ���� �׸���.
void CDRAW::printData(int& x, int& y, int type)
{
	if (x < 1)          x = 1;
	else if (y < 1)     y = 1;
	else if (x > SIZE)  x = SIZE;
	else if (y > SIZE)  y = SIZE;

	const int color[] = { BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK };
	const char* shape[] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };

	SetColor(color[type], DARK_YELLOW);
	// ������ ������ 9���� ����� �����ϱ�
	// ��� �׷��� ���� ��ǥ�� �ְ� ����� �����´�.
	if (type == LINE) type = getLineNumber(x, y);
	// ������ 0-8���� �̰�, �� �ڿ� ���� ��ġ�Ǿ� ������ 9�� �����ش�.
	else type += 9;
	gotoxy((x + nX - 1) * 2, y + nY - 1);
	printf("%s", shape[type]);
	SetColor(GRAY);
}

// ���ο� �������� ��ǥ�� ���ڿ� ���ĺ����� ǥ�����ش�.
// ���γ� ���ο� ���ڳ� ���ĺ����� �����ϸ� ��ǥ�� ǥ���� ��
// ȥ���� �� �� ������ ������ ǥ���Ѵ�.
void CDRAW::printNum()
{
	SetColor(BLACK, DARK_YELLOW);
	//x���� ���
	for (int i = 0; i < SIZE; i++)
	{
		gotoxy((nX + i) * 2, nY + SIZE);
		printf("%2c", i + 'A');
	}
	//y���� ���
	for (int i = 0, j = SIZE; i < SIZE; i++, j--)
	{
		gotoxy((nX - 1) * 2, nY + j - 1);
		printf("%2d", i + 1);
	}
	gotoxy((nX - 1) * 2, nY + SIZE);
	printf("  ");
	SetColor(GRAY);
}

//������
//������
//������
//������ �Ʒ��� ���� �Ѵ�.
//0 1 2
//������
//3 4 5
//������
//6 7 8
//������
// �� ����� �ٵ����� ������̴�
// �ٵ����� ��� �����
// �� 9���� ��縸 ������ �׷��� �� �ִ�.
// x�� 0�϶��� ���� ��
// y�� 0�϶��� ���� ����
// x,y���� ���� ����� ��ȣ�� ��ȯ�Ѵ�.

// �ٵ��� ��ü�� �׷��ְ� �ٽ� �׷��� ������
// �׷��� �ϸ� ���� Size�� 19�� �ϰ� ������
// ��ü�� �����ؾ� �ǰ�, ���� ȭ���� ���� �Ÿ� �� �־
// �ʿ��� ���� �׶��׶� �׷��ַ� �̷� �۾��� �Ѵ� ���̴�.
int CDRAW::getLineNumber(int x, int y)
{
	// ���� ������
	if (x == 1)
	{
		// x, y�� �� 0�̸� ���� ��� �𼭸�
		if (y == 1) return 0;
		// ���� �ϴ� �𼭸�
		else if (y == SIZE) return 6;
		// ���� ������
		else return 3;
	}
	// ������ ������
	else if (x == SIZE)
	{
		// ������ ��� �𼭸�
		if (y == 1) return 2;
		// ������ �ϴ� �𼭸�
		else if (y == SIZE) return 8;
		// ������ ������
		else return 5;
	}
	// ���� ������
	else if (y == 1) return 1;
	// �Ʒ��� ������
	else if (y == SIZE) return 7;
	// ������ ��� + ���
	else return 4;
}

//���� �ð��� ȭ�鿡 ǥ�����ش�.
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
// openSource�� ����ϰ� �����  �۸�� ������
// ���� ������� ����� �˰����� �ռ��Ͽ�
// ���Ӱ� Omokrule class�� ����� ���� ���α׷��� �����غ���.

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
		//�ٵ��� ���� �迭�� ���� LINE�̳� STONE�� �ƴ� 
		//�ٸ� ���ڷ� ���������ν� ������� ��Ÿ����. 
		nBoard[i][0] = nBoard[i][SIZE + 1] = -1;
		nBoard[0][i] = nBoard[SIZE + 1][i] = -1;
	}
}

// �����ϱ� ���� �ٵ��� ���¸� �����Ѵ�. 
void COMOKRULE::SetBoard(int(*arr)[SIZE + 2])
{
	for (int i = 1; i <= SIZE; i++)
		for (int j = 1; j <= SIZE; j++)
			nBoard[i][j] = arr[i][j];
}

// x, y��ǥ�� ���� ���ų� ����.
// ���ٴ� ���� �װ���  Line�� �ٽ� �׷��ִ� �� �ǹ��Ѵ�. 
void COMOKRULE::SetStone(int x, int y, int nStone)
{
	nBoard[y][x] = nStone;
}

// 8���� ���ڴ� 8������ ��Ÿ����.
// �迭�� ������� ��, ��, ��, ��, ����, ����, ����, �ϵ�
// (��, ��) (�� ��) (����, ����) (����, �ϵ�)�� �ѽ��̵Ǿ�
// ���� ���� �� �밢���� ������ dx, dy�� ǥ���� Table 
void COMOKRULE::GetDirTable(int& x, int& y, int nDir)
{
	//          ��  ��  ��  ��  �ϼ� ���� ���� �ϵ� 
	int dx[] = { -1,  1,  0,  0, -1,   1,  -1,   1 };
	int dy[] = { 0,  0, -1,  1, -1,   1,   1,  -1 };

	x = dx[nDir];
	y = dy[nDir];
}

// �־��� �������� ��ǥ�� �Ű� ����� ã�� 
// �װ��� ��ǥ�� �˷��ش�. 
bool COMOKRULE::IsEmpty(int& x, int& y, int nStone, int nDir)
{
	int dx, dy;

	// ���� Table���� dx, dy���� �����´�.
	// ���� nDir�� 0�̶�� dx = -1, dy = 0�̴�. 
	GetDirTable(dx, dy, nDir);
	// x�� 1 y�� 0�̴ϱ� x += dx, y += dy �� ���Ŀ� ���ؼ� 
	// x�� ���� �۾��� �������� ����, y�� ������ ������ ���ڸ�
	// �׷��� ���η� ���ʿ� nStone�� �ƴ� ������ ���߰� �ȴ�. 
	for (; nBoard[y][x] == nStone; x += dx, y += dy);

	// nStone�� �ƴ϶� �ؼ� ���� LINE�̶� �� �� ����.
	// �ٸ� ���̰ų� �ٵ����� ��� �� �ϼ��� ������
	// �װ��� LINE�� ���� ���� ��ȯ�Ѵ�. 
	if (nBoard[y][x] == LINE) return true;
	else return false;
}

// �־��� ��ǥ�� ������ �����ϰ�,
// �־��� ����(nDir)���� 
// ���ӵ� ���� ����� ��� ��ȯ�Ѵ�. 
int COMOKRULE::GetStoneCount(int x, int y, int nStone, int nDir)
{
	int dx, dy;
	int tx = x;
	int ty = y;
	int cnt = 0;

	// ������ ���� Line�� �ƴϸ� ������ �� ������
	// 0�� return�Ѵ�. 
	if (nBoard[y][x] != LINE) return 0;
	SetStone(x, y, nStone);

	// ���� Table���� dx, dy���� ������ 
	GetDirTable(dx, dy, nDir);
	//������ ���������� nDir�������� ���� ���� ������ ����. 
	for (; nBoard[y][x] == nStone; x += dx, y += dy) cnt++;

	// ���� Table�� �ϳ��� �Ǿ��ְ�, 
	// ������ �׻� ���� �Ǵ� �ϳ����� �Ǿ� �־� 
	// nDir�� Ȧ���� ���� -1�� ������ �˻��Ͽ��� �Ѵ�.
	// �׷��� �ʰ� ���� �����̶�� ������ +1�Ѵٸ�
	// ���� nDir�� ��(1)�̶�� ��(0)���� �˻��ؾ� �Ǵµ�
	// +1�ؼ� 2�� �Ǹ� ��(0)�� �ƴ� ��(2)�� �˻��ϰ� �ȴ�. 
	// �̸� �����ϱ� ���� 3�� �����ڸ� �̿���
	// ���ǿ� �´� ������ �μ��� �ѱ�� �Ͽ���. 
	GetDirTable(dx, dy, nDir % 2 ? nDir - 1 : nDir + 1);

	// x, y���� ������ ������ �ϴ��� ó�� ��ǥ�� ����� ������
	// ó�� ��ǥ���� ���� �������� ��ĭ �Űܼ� �װ���������
	// ���� ������ ����. 
	// ������ �� ���Ҵ� ���� �����⿡ �ߺ��� ���ϱ� ���ؼ���. 
	x = tx + dx;
	y = ty + dy;
	for (; nBoard[y][x] == nStone; x += dx, y += dy) cnt++;

	// ���� ������ �� �������� ���� ����. 
	SetStone(tx, ty, LINE);
	return cnt;
}

// ������ �Ͽ����� �������� �˻��Ѵ�. 
bool COMOKRULE::IsFive(int x, int y, int nStone)
{
	// ���� Table�� ���� 8�̴ϱ� 8���� �˻��ϰ�
	// �������� +=2�ΰ�
	// �Ʒ� GetStoneCount()�Լ� �ȿ��� �糡�� �˻��ϱ� �����̴�. 
	for (int i = 0; i < 8; i += 2)
	{
		if (GetStoneCount(x, y, nStone, i) == 5) return true;
	}
	return false;
}

// ���� ���� ���������� �˻�������,
// nDir���⿡ ���ؼ��� �˻��Ѵ�.
// �̴� Four�� OpenFour�� �Ǵ��� �˾ƺ��� ���Ͽ� 
// ����� ���� �ϳ��� ���ƺ��鼭
// ������ �Ǵ��� �˻��ϱ� ���ؼ���. 
bool COMOKRULE::IsFive(int x, int y, int nStone, int nDir)
{
	if (GetStoneCount(x, y, nStone, nDir) == 5) return true;
	return false;
}

// ������ �˻��ϴ� �Ͱ� ���� 6�� �̻����� �˻��Ѵ�. 
bool COMOKRULE::IsSix(int x, int y, int nStone)
{
	for (int i = 0; i < 8; i += 2)
	{
		if (GetStoneCount(x, y, nStone, i) >= 6) return true;
	}
	return false;
}

// ������ ������ 4������ �˻��Ѵ�.
bool COMOKRULE::IsFour(int x, int y, int nStone, int nDir)
{
	// ������ ��ǥ x, y�� ����ϱ� ���� ����
	int tx, ty;

	// �� ���⿡ ���Ͽ� �糡�� �˻��ϴµ�
	// �ѽ��� ��ǥ�� ù��°���� �˻��ϱ� ���Ͽ�
	nDir % 2 ? nDir -= 1 : nDir;
	// ��ǥ�� ������ �Ѵ�
	SetStone(x, y, nStone);
	// ���� �糡�� �˻�
	for (int i = 0; i < 2; i++)
	{
		// ������ ��ǥ�� �߽����� �־��� ����(nDir)�� ���Ͽ�
		// �������� �̵��ϸ鼭 ����� ã�� �װ��� ��ǥ�� ���;� �Ǳ⿡
		// ������ ��ǥ�� ������ �ȴ�. ���� ������ �˻��ϱ����Ͽ�
		// ����� ������ �ʿ��ϰ�, �Ź� �Ʒ��� ����
		// ������ ��ǥ�� �޾Ƽ� �˻簡 ����Ǿ�� �Ѵ�.
		tx = x;
		ty = y;
		// ����� ������ �� ��ǥ�� �޾ƿ´�.
		if (IsEmpty(tx, ty, nStone, nDir + i))
		{
			// �� ������� ������ �Ǵ��� �˻��Ѵ�.
			if (IsFive(tx, ty, nStone, nDir + i))
			{
				// ������ �Ǿ��ٸ� 4�̱� ������
				// ���� ���� ���� �����Ѵ�.
				SetStone(x, y, LINE);
				return true;
			}
		}
	}

	// �˻縦 �غ����� 4�� �ƴ϶� �ص� ���� ����.
	SetStone(x, y, LINE);
	return false;
}

// ���� �������� 4���̰� ���� ���� �������� ������ �Ǹ�
// ����4�� �ȴ�.
int COMOKRULE::IsOpenFour(int x, int y, int nStone, int nDir)
{
	int tx, ty;
	// ����4�� �ɶ��� ���ʿ� ���� ��������
	// ���� ��� ������ �Ǿ�� �Ǳ⶧����
	// �ΰ��� 4�� �Ǵ��� �˻縦 ���� ����
	int sum = 0;

	nDir % 2 ? nDir -= 1 : nDir;
	SetStone(x, y, nStone);
	for (int i = 0; i < 2; i++)
	{
		tx = x;
		ty = y;
		// ��������� Four()�Լ��� ����.
		if (IsEmpty(tx, ty, nStone, nDir + i))
		{
			if (IsFive(tx, ty, nStone, nDir + i)) sum++;
		}
	}
	SetStone(x, y, LINE);

	// �������� ��ΰ� ������ �Ǿ������� ����4�̴�.
	if (sum == 2)
	{
		// ����4�� ���� Ư���ϰ� ���ٿ� 44�� �ɼ� �ִ�.
		// 1234567   12345678
		// 0 0 0 0   00  0 00
		// ���� ���� ��Ȳ���� 4��ġ�� ���� ���̸�
		// ������ ��� 4�� �Ǿ� ���ٿ��� 44�� �߻��Ѵ�.
		// ������ 0000 �̿Ͱ��� �����϶��� 4�� �ϳ��̱� ������
		// �˻縦 �Ͽ� ������ ��Ȯ�ϰ� �Ѵ�.
		if (GetStoneCount(x, y, nStone, nDir) == 4) sum = 1;
	}
	// sum�� 2�� �ƴϸ� ����4�� �ƴϹǷ� 0
	else sum = 0;

	return sum;
}

bool COMOKRULE::IsDoubleFour(int x, int y, int nStone)
{
	int cnt = 0;

	//��ǥ�� �߽����� ������ �ٿ����Ͽ� 4�� �˻��Ѵ�.
	for (int i = 0; i < 8; i += 2)
	{
		// OpenFour()������ �� �ٿ� 44�� ���� �� ������ �˻��ϰ�
		if (IsOpenFour(x, y, nStone, i) == 2) return true;
		// ����4�� 4�̴� 4�� �˻��Ͽ� 2�� �̻��̸� 44�̴�.
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
			// 33�� ���� �ϳ� �� ������ �� �ݵ�� ����4�̾�� �ǰ�,
			// �� �� ���� �ڸ��� 44, 6��, �Ǵٸ� 33
			// �� �ݼ��ڸ��� �ƴϾ�� �ȴ�.
			if ((IsOpenFour(tx, ty, nStone, nDir) == 1) && (!IsForbidden(tx, ty, nStone)))
			{
				// �� ������ �����ϴ� �ڸ��̸� 3�̹Ƿ� ���� �����ϰ� ���� �����Ѵ�.
				SetStone(x, y, LINE);
				return true;
			}
		}
	}

	SetStone(x, y, LINE);
	return false;
}

// 33�� �˻��Ѵ�.
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

// �ݼ��ڸ��� �˻��Ѵ�.
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

	// Undo�� Redo�� ���� top pointer 
	static int  uTop, rTop;
	// last ������ 
	static int  lx, ly;

	// Ŀ���� �������� �����ϱ� ���� �ð�
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

//�ٵ��� ���۵� �� �ʱ�ȭ 
void COMOK::initOmok()
{
	drawBoard();
	initBoard();
	t2 = clock();
	// 1�ʿ� �ѹ��� �׸��µ� ������ �α� ���ؼ�
	// ��������� 500msec���� Ŀ��ó�� ���ڰŸ��� �ȴ�. 
	t1 = clock() - 500;
	pDraw()->infoKey();
	uTop = rTop = -1;
}

//Ŀ���� �̵��ϱ��� ���� �ٵ����� �����Ѵ�. 
void COMOK::setBoard(int x, int y)
{
	pDraw()->printData(x, y, arrBoard[y][x]);
	// Ŀ���� �̵����϶� Ŀ���� ������ �ʰ� �Ѵ�.
	// �������� �� ������ �ʾ� �����̵��� �ð� ����  
	t2 = clock() - 400;
	t1 = clock() - 900;
}

// Ŀ���� ����� Ŀ��ó�� ���̰� �Ѵ�.
void COMOK::cursorView(int x, int y)
{
	// Ŀ���� 1�ʴ����� �׷��ش�. 
	if (clock() - t1 >= 1000)
	{
		pDraw()->printData(x, y, CURSOR);
		t1 = clock();
	}
	// Ŀ�� ��ġ�� �ٵ����� 1�� ������ �׷��ش�. 
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

// �ٵ����� �׸���. 
void COMOK::drawBoard()
{
	pDraw()->printNum();
	for (int i = 1; i <= SIZE; i++)
		for (int j = 1; j <= SIZE; j++)
			pDraw()->printData(j, i, LINE);
}

// ���� ���̸� �迭�� ��鵹�� �����Ѵ�.
// ó�� �浹�� �߾ӿ� �Ѽ� ���� �����Ѵ�. 
void COMOK::initBoard()
{
	for (int i = 0; i < SIZE + 2; i++)
		for (int j = 0; j <= SIZE + 2; j++)
			arrBoard[i][j] = LINE;
	arrBoard[CENTER][CENTER] = BLACK_STONE;
}

// �ٵϾ� ���� �ڸ��� üũ�Ѵ�. 
bool COMOK::isOccupy()
{
	return arrBoard[y][x] != LINE;
}

// �ٵϾ��� ���� �Ǹ� ���忡 �ٵϾ��� �׸���
// ���� �迭�� �����Ѵ�.  
void COMOK::saveBoard(int stone)
{
	pDraw()->printData(x, y, stone);
	arrBoard[y][x] = stone;
	undoSet(stone);
}

// Game class���� �޾ƿ� ��ǥ�� �����Ѵ�.
void COMOK::setXY(int ax, int ay)
{
	x = ax;
	y = ay;
}

// ������ �����Լ�
// ������ �������� üũ�ϰ�
// ������ �Ǹ� ������ �Ѵ�.
// �������� �������� �˻��Ͽ� ����� �����Ѵ�.
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
// Renju rule�� �������� ���� �Ǳ⶧���� ������ class�� �и��Ͽ���.
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

		// ���ַ꿡�� ���� ����� ��ó�� 
		// ��� �ݼ��� ���ǹǷ� ���� ���� �ȴ�. 
	case 31:
	case 11: return &gomoku_White;
	case 20: return &general_Black;
	case 21: return &general_White;
	case 30: return &renju_Black;
	}
}

//----------------------------------------------------------- Game class
// Game������ �����ϴ� class
class CGAME
{
private:
	// t1 : 1�ʸ��� ȭ�鿡 �ð��� ǥ�����ֱ� ���� ����
	// ���ʸ��� �ʱ�ȭ
	// t2 : ������ ���� �ɶ� �ʱ�ȭ �Ͽ�
	// ������ ����� ������ �����ϸ鼭 ���ؽð��� �ȴ�.
	// t3 : �ð������� �ʿ��Ҷ� ����� ����
	time_t  t1, t2, t3;
	//���� ������ �� ��
	int     curStone;
	// omok�� x, y�� ���� ��ǥ�� �����Ѵ�.
	int     x, y;

	// ���ºθ� �˱� ���ؼ� ������ �̷��� ���� �ʿ��ϴ�.
	// ������ pass��  �ϸ� passTrigger�� On���°� �ȴ�.
	// �׷� passCounter�� ���۵ǰ�
	// �������� �鵹�� �浹�� �������� ��������
	// �ƴϸ� ���� ���� �������� pass�� ������
	// �Ǵ��ϱ� ���Ͽ� stoneState�� �迭�� �����.
	// ���º����� �˸��°� �ǿܷ� �����ϴ�.
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

// ������ �����Ҷ� �ʿ��� �������� �ʱ�ȭ �ϰ�,
// ȭ�鿡 ǥ�����ش�. 
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

// main�Լ����� �� �Լ��� ȣ���ϸ� ������ ���۵ȴ�. 
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
		// 1�ʸ��� ȭ�鿡 �ð��� ǥ���Ѵ�. 
		if (clock() - t1 >= 1000) drawTime();

		result = checkKey();
		switch (result)
		{
			// Ű����κ��� ESCŰ�� ������ ������ �����Ѵ�. 
		case FINISH: return false;
			// ������ �Ǿ����� ���ڸ� �˸���, ����Ұ��� �����. 
		case FIVEMOK: return pDraw()->endMsg(curStone);
			// ������ �Ұ����� ���� �� ������ �˸���. 
		case OCCUPIED:
		case SAMSAM:
		case SASA:
		case SIXMOK:
		case NOTUNDO:
			pDraw()->errMsg(result);
			pOmok[curStone]->setBoard(x, y);
			break;
			//������ �ưų�, �Ѽ� ������ �� ���� �ٲ۴�.  
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

// ��� ���� �� ���ʸ� �ٲ۴�. 
void CGAME::changeStone()
{
	// ��� ���̴� ���ؼ� 2�� ������ ��ȯ�� �ȴ�. 
	curStone = (curStone + 1) % 2;
	// ���� �� ���ʸ� �˷��ش�. 
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

// 1 �ʸ��� ȭ�鿡 �ð��� ǥ���Ѵ�. 
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

