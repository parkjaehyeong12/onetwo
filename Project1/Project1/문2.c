#include<stdio.h>
int two(int sec)
{
	if (sec >= 3600)
	{
		printf("����!");
		return -1;
	}
	printf("%d�� %d��\n", sec / 60, sec % 60);
	return sec / 60;
}
int main()
{
	printf("�ʰ��� �Է��ϼ��� ");
	int sec;
	scanf_s("%d", &sec);
	int result = two(sec);
	printf("���� %d", result);
	return 0;
}