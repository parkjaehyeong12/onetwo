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
	printf(" ���� �� ���� \n");
	x = 20, y = 7;
	goxy(x, y);
	printf("�浹�� ���� ���� �Ӵϴ�.\n");
	y = 9;
	printf("�浹�� 3x3, 4x4 ���� �� �� �����ϴ�.\n");
	y = 11;
	goxy(x, y);
	printf("���� 5�� �̻� ����Ǹ� �¸��մϴ�.\n");
	y = 13;
	goxy(x, y);
	printf("������ �����Ͻ÷��� Space Bar�� ��������\n");
	y = 15;
	goxy(x, y);
	printf("������ �����Ͻ÷��� ESC�� �����ּ���\n");
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
		} //�ٵ��� 2���� �迭 10�� �� 10ȣ�� 0�� �־���.
	goxy(50, 5);
	printf("�浹 �����Դϴ�.");
	goxy(0, 0);
	Paint_Board();//�ٵ��� �׸���
	int x=18, y=8;
	goxy(x, y);
	Define_Stone();//���� �� ����

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
	printf("�� ");//��ǥ �Ű� �Ⱦ��� �׳� �׸��� ��
	for (i = 0; i < 17; i++)
		printf("�� ");
	printf("��\n");
	for (i = 0; i < 17; i++)
	{
		printf("�� ");
		for (j = 0; j < 17; j++)
			printf("�� ");
		printf("��\n");
	}
	printf("�� ");
	for (i = 0; i < 17; i++)printf("�� ");
	printf("��");
}
void Define_Stone() //Į�� ���� ���� �� ����
{
	if (Color == 1)
		printf("��");
	else
		printf("��");
}
void ResetStone(int x, int y) //Ŀ���� �����ΰ� �ԷµǸ� ���� ��ġ x,y �ڸ���
{                             //�ٵ����� �޿������鼭 ����
	if (x == 0 && y == 0)
		printf("��");
	else if (x == 36 && y == 0)
		printf("��");
	else if (x == 0&& y ==18)
		printf("��");
	else if(x ==36 && y ==18)
		printf("��");
	else if (x == 0)
		printf("��");
	else if(y == 0)
		printf("��");
	else if(x == 36)
		printf("��");
	else if(y ==18)
		printf("��");
	else
		printf("��");
}
void Action(char key,int*x, int*y)
{
	//�̵��ϱ� �� ��ǥ�̵����ְ� +  �����̽��� �ÿ� Į���� ����
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