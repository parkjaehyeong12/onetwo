#include<stdio.h>

int calcAge()
{
	int year;
	printf("�� �⵵ �¾? ");
	scanf_s("%d", &year);
	return 2023 - year; //�ѱ��� ����
}
int main()
{
	//4
	printf("���� %d���Դϴ�.\n",calcAge());


	return 0;
}