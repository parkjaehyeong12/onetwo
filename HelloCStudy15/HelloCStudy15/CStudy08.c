//1.�¾ ������ �Ű������� �ް� ���� ������
#include<stdio.h>
char* outputThee(int year)
{
	switch (year % 12)
	{
	case 0:
		return "������";
	case 1:
		return "��";
	case 2:
		return "��";
	case 3:
		return "����";
	case 4:
		return "��";
	case 5:
		return "��";
	case 6:
		return "ȣ����";
	case 7:
		return "�䳢";
	case 8:
		return "��";
	case 9:
		return "��";
	case 10:
		return "��";
	case 11:
		return "��";
	default:
		return "����";
	}
}
char* moreEasy(int year)
{
	year %= 12;
	//2���� �迭�� ����. //1¥�� ����ĭ�̶�� �����غ�
	static char thees[12][10]
		= { "������","��","��","����","��","��","ȣ����","�䳢","��","��","��","��" };
	return thees[year]; //static �� �����س��� �Լ��� ������, �迭�� �����ִ´�.
}
int main()
{
	char thee[10];
	int year;
	printf("����? ");
	scanf_s("%d", &year);
	printf("%s\n", outputThee(year));
	printf("%s\n",moreEasy(year));

	return 0;
}