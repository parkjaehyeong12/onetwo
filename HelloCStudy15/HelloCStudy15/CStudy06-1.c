#include<stdio.h>
#include<string.h>
char* animal(int year)
{
	year %= 12;
	switch (year)
	{
	case 0:
		return "�����̶�\n";
	case 1:
		return "�߶�\n";
	case 2:
		return "����\n";
	case 3:
		return "������\n";
	case 4:
		return "���\n";
	case 5:
		return "�Ҷ�\n";
	case 6:
		return "ȣ���̶�\n";
	case 7:
		return "�䳢��\n";
	case 8:
		return "���\n";
	case 9:
		return "���\n";
	case 10:
		return "����\n";
	case 11:
		return "���\n";
	default:
		return "�ƹ��͵� �ƴ϶�\n";
		break;
	}

}

void q2(int year)
{/*
#pragma region �� �迭�ȿ� ǥ��

	if(0)
	{ 
	int gan = year % 10;
	rewind(stdin);
	static char ganzi[3];
	switch (gan)
	{
	case 0:
		ganzi[0] = "��";
		break;
	case 1:
		ganzi[0] = "��";
		break;
	case 2:
		ganzi[0] = "��";
		break;
	case 3:
		ganzi[0] = "��";
		break;
	case 4:
		ganzi[0] = "��";
		break;
	case 5:
		ganzi[0] = "��";
		break;
	case 6:
		ganzi[0] = "��";
			break;
	case 7:
		ganzi[0] = "��";
		break;
	case 8:
		ganzi[0] = "��";
		break;
	case 9:
		ganzi[0] = "��";
		break;
	default:
		ganzi[0] = "����\n";
		break;
	}
	int zi = year % 12;
	switch (zi)
	{
	case 0:
		ganzi[1] = "��\n";
		break;
	case 1:
		ganzi[1] = "��\n";
		break;
	case 2:
		ganzi[1] = "��\n";
		break;
	case 3:
		ganzi[1] = "��\n";
		break;
	case 4:
		ganzi[1] = "��\n";
		break;
	case 5:
		ganzi[1] = "��\n";
		break;
	case 6:
		ganzi[1] = "��\n";
		break;
	case 7:
		ganzi[1] = "��\n";
		break;
	case 8:
		ganzi[1] = "��\n";
		break;
	case 9:
		ganzi[1] = "��\n";
		break;
	case 10:
		ganzi[1] = "��\n";
		break;
	case 11:
		ganzi[1] = "��\n";
		break;
	default:
		ganzi[1] = " ����\n";
		break;
	}

	return ganzi;
	}
#pragma endregion
*/
	int a = year % 10;
	int b = year % 12;
	switch (a)
	{
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	default:
		printf("�����Դϴ�. ");

	}
	switch (b)
	{
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	case 10:
		printf("��");
		break;
	case 11:
		printf("��");
		break;
	default:
		printf(" �����Դϴ�. ");
	}

}
char* qq2(int year)
{
	char result1[10];
	char result2[10];
	int a = year % 10;
	int b = year % 12;
	switch (a)
	{
	case 0:
		strcpy_s(result1, 3 , "��");
		break;
	case 1:
		strcpy_s(result1,3, "��");
		break;
	case 2:
		strcpy_s(result1,3, "��");
		break;
	case 3:
		strcpy_s(result1,3, "��");
		break;
	case 4:
		strcpy_s(result1,3, "��");
		break;
	case 5:
		strcpy_s(result1,3, "��");
		break;
	case 6:
		strcpy_s(result1,3, "��");
		break;
	case 7:
		strcpy_s(result1,3, "��");
		break;
	case 8:
		strcpy_s(result1,3, "��");
		break;
	case 9:
		strcpy_s(result1,3, "��");
		break;
	default:
		printf("�����Դϴ�. ");

	}
	switch (b)
	{
	case 0:
		strcpy_s(result2,3, "��");
		break;
	case 1:
		strcpy_s(result2,3, "��");
		break;
	case 2:
		strcpy_s(result2,3, "��");
		break;
	case 3:
		strcpy_s(result2,3, "��");
		break;
	case 4:
		strcpy_s(result2,3, "��");
		break;
	case 5:
		strcpy_s(result2,3, "��");
		break;
	case 6:
		strcpy_s(result2,3, "��");
		break;
	case 7:
		strcpy_s(result2,3, "��");
		break;
	case 8:
		strcpy_s(result2,3, "��");
		break;
	case 9:
		strcpy_s(result2,3, "��");
		break;
	case 10:
		strcpy_s(result2,3, "��");
		break;
	case 11:
		strcpy_s(result2,3, "��");
		break;
	default:
		printf(" �����Դϴ�. ");
	}
	return result1;
}

int main()
{
	//1
	printf("���� �¾ ������? ");
	int year;
	scanf_s("%d", &year);
	printf("%s\n",animal(year));
	
	//printf("%s\n", q2(year));

	//2
	printf("�¾ ���� �ٽ� �Է� ");
	scanf_s("%d", &year);
	int a = year % 10;
	int b = year % 12;
	switch (a)
	{
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	default :
		printf("�����Դϴ�. ");

	}
	switch (b)
	{
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	case 10:
		printf("��");
		break;
	case 11:
		printf("��");
		break;
	default:
		printf(" �����Դϴ�. ");
	}
	printf("\n\n");
	printf("�¾ ���� �ٽ� �Է� ");
	scanf_s("%d", &year);
	
	//2-1
	q2(year);

	//2-2
	printf("\n�¾ ���� �ٽ� �Է� ");
	scanf_s("%d", &year);
	printf("%s", qq2(year));


	
	return 0;
}