#include<stdio.h>
void season()
{
	int month;
	printf("q2 �����? ");
	scanf_s("%d", &month);
	if (month == 12 || month == 1 || month == 2)
		printf("�ܿ�\n");
	else if (month >= 3 && month <= 5)
		printf("��\n");
	else if (month >= 6 && month <= 8)
		printf("����\n");
	else if (month >= 9 && month <= 11)
		printf("����\n");
	else
		printf("����\n");
}
void printSeason(int month)
{
	switch (month)
	{
	case 12:
		month = 6; //�������� ������. ()�ȿ� ���� ���� �ǹ̰� �ִ���
	case 1:
	case 2:
		printf("Winter is coming\n");
		break;
	case 3:
	case 4:
	case 5:
		printf("Spring\n");
		break;
	case 6:
	case 7:
	case 8:
		printf("Daegu is coming\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("����, �����佺�� ����\n");
	default:
		printf("����\n");
		break;
	}
}

int main()
{
	//2
	season();

	//3
	int m;
	printf("q3 �¾ ���� �Է� ");
	scanf_s("%d", &m);
	printSeason(m);


	return;
}