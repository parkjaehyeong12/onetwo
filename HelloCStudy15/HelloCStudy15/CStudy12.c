#include<stdio.h>
//3 �¾ ���� ���ڿ��� �ް� ������ ���ڿ��� �����Ͻÿ�
char* season(int month)
{
	switch (month)
	{
	case 12:
	case 1:
	case 2:
		return "�ܿ�";
	case 3:
	case 4:
	case 5:
		return "��";
	case 6:
	case 7:
	case 8:
		return "����";
	case 9:
	case 10:
	case 11:
		return "����";
	default:
		return "����";
	}
}

//4 ���ڿ� ���� ���ϱ�
int length(char* str)
{
	int len = 0;
	while (str[len] != NULL)
	{
		if (str[len])
			continue;
		else;
		len++;
	}
	return len;
}

int main()
{
	printf("%s\n", season(4));
	printf("%d\n", length("��spring2022"));
	return 0;
}