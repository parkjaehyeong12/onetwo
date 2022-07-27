#include<stdio.h>
//3 태어난 월을 문자열로 받고 계절을 문자열로 리턴하시오
char* season(int month)
{
	switch (month)
	{
	case 12:
	case 1:
	case 2:
		return "겨울";
	case 3:
	case 4:
	case 5:
		return "봄";
	case 6:
	case 7:
	case 8:
		return "여름";
	case 9:
	case 10:
	case 11:
		return "가을";
	default:
		return "오류";
	}
}

//4 문자열 길이 구하기
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
	printf("%d\n", length("봄spring2022"));
	return 0;
}