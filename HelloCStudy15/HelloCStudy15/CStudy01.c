#include<stdio.h>

int main()
{
	int month;
	printf("q1 �¾ ���� �Է� ");
	scanf_s("%d", &month);
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

	
	switch (month)
	{
	case 6:
		printf("����\n");
		break;
	default:
		break;
	}

	return 0;
}