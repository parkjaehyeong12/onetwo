#include<stdio.h>
int two(int sec)
{
	if (sec >= 3600)
	{
		printf("오류!");
		return -1;
	}
	printf("%d분 %d초\n", sec / 60, sec % 60);
	return sec / 60;
}
int main()
{
	printf("초값을 입력하세요 ");
	int sec;
	scanf_s("%d", &sec);
	int result = two(sec);
	printf("값은 %d", result);
	return 0;
}