#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

char* ganzi(int year)
{
	char result1[50];
	char result2[10];
	int a = year % 10;
	int b = year % 12;
	switch (a)
	{
	case 0:
		strcpy_s(result1, 3, "��");
		break;
	case 1:
		strcpy_s(result1, 3, "��");
		break;
	case 2:
		strcpy_s(result1, 3, "��");
		break;
	case 3:
		strcpy_s(result1, 3, "��");
		break;
	case 4:
		strcpy_s(result1, 3, "��");
		break;
	case 5:
		strcpy_s(result1, 3, "��");
		break;
	case 6:
		strcpy_s(result1, 3, "��");
		break;
	case 7:
		strcpy_s(result1, 3, "��");
		break;
	case 8:
		strcpy_s(result1, 3, "��");
		break;
	case 9:
		strcpy_s(result1, 3, "��");
		break;
	default:
		printf("�����Դϴ�. ");

	}
	switch (b)
	{
	case 0:
		strcpy_s(result2, 3, "��");
		break;
	case 1:
		strcpy_s(result2, 3, "��");
		break;
	case 2:
		strcpy_s(result2, 3, "��");
		break;
	case 3:
		strcpy_s(result2, 3, "��");
		break;
	case 4:
		strcpy_s(result2, 3, "��");
		break;
	case 5:
		strcpy_s(result2, 3, "��");
		break;
	case 6:
		strcpy_s(result2, 3, "��");
		break;
	case 7:
		strcpy_s(result2, 3, "��");
		break;
	case 8:
		strcpy_s(result2, 3, "��");
		break;
	case 9:
		strcpy_s(result2, 3, "��");
		break;
	case 10:
		strcpy_s(result2, 3, "��");
		break;
	case 11:
		strcpy_s(result2, 3, "��");
		break;
	default:
		printf(" �����Դϴ�. ");
	}
	printf("%s%s", result1, result2);


	strcat(result1, result2);
	return result1;
}
char* birthMonth(int month)
{
	month %= 12;
	switch (month)
	{
	case 12:
	case 1:
	case 2:
		return "�ܿ�\n";
	case 3:
	case 4:
	case 5:
		return "��\n";
	case 6:
	case 7:
	case 8:
		return "����\n";
	case 9:
	case 10:
	case 11:
		return "����\n";
	default:
		return "����\n";
	}
}

int main()
{
	//2�� ��¸� ���ϵ�
	int year;
	printf("�ظ� �Է� ");
	scanf_s("%d", &year);
	printf("\n%s\n",ganzi(year));

	//3
	printf("�¾ ���� �޾ƿ� ");
	int month;
	scanf_s("%d", &month);
	printf("%s", birthMonth(month));

	//4
	printf("�ѱ����� �����̳� ���ڸ�");

	return 0;
}
	/* ���ڿ� ���� ���¹��
	for (int i = 0; a[i] != NULL; i++)
	{
		count++;
	}
*/