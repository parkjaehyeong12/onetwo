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
		strcpy_s(result1, 3, "경");
		break;
	case 1:
		strcpy_s(result1, 3, "신");
		break;
	case 2:
		strcpy_s(result1, 3, "임");
		break;
	case 3:
		strcpy_s(result1, 3, "계");
		break;
	case 4:
		strcpy_s(result1, 3, "갑");
		break;
	case 5:
		strcpy_s(result1, 3, "을");
		break;
	case 6:
		strcpy_s(result1, 3, "병");
		break;
	case 7:
		strcpy_s(result1, 3, "정");
		break;
	case 8:
		strcpy_s(result1, 3, "무");
		break;
	case 9:
		strcpy_s(result1, 3, "기");
		break;
	default:
		printf("오류입니다. ");

	}
	switch (b)
	{
	case 0:
		strcpy_s(result2, 3, "신");
		break;
	case 1:
		strcpy_s(result2, 3, "유");
		break;
	case 2:
		strcpy_s(result2, 3, "술");
		break;
	case 3:
		strcpy_s(result2, 3, "해");
		break;
	case 4:
		strcpy_s(result2, 3, "자");
		break;
	case 5:
		strcpy_s(result2, 3, "축");
		break;
	case 6:
		strcpy_s(result2, 3, "인");
		break;
	case 7:
		strcpy_s(result2, 3, "묘");
		break;
	case 8:
		strcpy_s(result2, 3, "진");
		break;
	case 9:
		strcpy_s(result2, 3, "사");
		break;
	case 10:
		strcpy_s(result2, 3, "오");
		break;
	case 11:
		strcpy_s(result2, 3, "미");
		break;
	default:
		printf(" 오류입니다. ");
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
		return "겨울\n";
	case 3:
	case 4:
	case 5:
		return "봄\n";
	case 6:
	case 7:
	case 8:
		return "여름\n";
	case 9:
	case 10:
	case 11:
		return "가을\n";
	default:
		return "오류\n";
	}
}

int main()
{
	//2번 출력만 리턴도
	int year;
	printf("해를 입력 ");
	scanf_s("%d", &year);
	printf("\n%s\n",ganzi(year));

	//3
	printf("태어난 달을 받아요 ");
	int month;
	scanf_s("%d", &month);
	printf("%s", birthMonth(month));

	//4
	printf("한글제외 영문이나 숫자만");

	return 0;
}
	/* 문자열 길이 세는방법
	for (int i = 0; a[i] != NULL; i++)
	{
		count++;
	}
*/