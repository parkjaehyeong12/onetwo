#include<stdio.h>
#include<string.h>
char* animal(int year)
{
	year %= 12;
	switch (year)
	{
	case 0:
		return "원숭이띠\n";
	case 1:
		return "닭띠\n";
	case 2:
		return "개띠\n";
	case 3:
		return "돼지띠\n";
	case 4:
		return "쥐띠\n";
	case 5:
		return "소띠\n";
	case 6:
		return "호랑이띠\n";
	case 7:
		return "토끼띠\n";
	case 8:
		return "용띠\n";
	case 9:
		return "뱀띠\n";
	case 10:
		return "말띠\n";
	case 11:
		return "양띠\n";
	default:
		return "아무것도 아니띠\n";
		break;
	}

}

void q2(int year)
{/*
#pragma region 한 배열안에 표시

	if(0)
	{ 
	int gan = year % 10;
	rewind(stdin);
	static char ganzi[3];
	switch (gan)
	{
	case 0:
		ganzi[0] = "경";
		break;
	case 1:
		ganzi[0] = "신";
		break;
	case 2:
		ganzi[0] = "임";
		break;
	case 3:
		ganzi[0] = "계";
		break;
	case 4:
		ganzi[0] = "갑";
		break;
	case 5:
		ganzi[0] = "을";
		break;
	case 6:
		ganzi[0] = "병";
			break;
	case 7:
		ganzi[0] = "정";
		break;
	case 8:
		ganzi[0] = "무";
		break;
	case 9:
		ganzi[0] = "기";
		break;
	default:
		ganzi[0] = "오류\n";
		break;
	}
	int zi = year % 12;
	switch (zi)
	{
	case 0:
		ganzi[1] = "신\n";
		break;
	case 1:
		ganzi[1] = "유\n";
		break;
	case 2:
		ganzi[1] = "술\n";
		break;
	case 3:
		ganzi[1] = "해\n";
		break;
	case 4:
		ganzi[1] = "자\n";
		break;
	case 5:
		ganzi[1] = "축\n";
		break;
	case 6:
		ganzi[1] = "인\n";
		break;
	case 7:
		ganzi[1] = "묘\n";
		break;
	case 8:
		ganzi[1] = "진\n";
		break;
	case 9:
		ganzi[1] = "사\n";
		break;
	case 10:
		ganzi[1] = "오\n";
		break;
	case 11:
		ganzi[1] = "미\n";
		break;
	default:
		ganzi[1] = " 오류\n";
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
		printf("경");
		break;
	case 1:
		printf("신");
		break;
	case 2:
		printf("임");
		break;
	case 3:
		printf("계");
		break;
	case 4:
		printf("갑");
		break;
	case 5:
		printf("을");
		break;
	case 6:
		printf("병");
		break;
	case 7:
		printf("정");
		break;
	case 8:
		printf("무");
		break;
	case 9:
		printf("기");
		break;
	default:
		printf("오류입니다. ");

	}
	switch (b)
	{
	case 0:
		printf("신");
		break;
	case 1:
		printf("유");
		break;
	case 2:
		printf("술");
		break;
	case 3:
		printf("해");
		break;
	case 4:
		printf("자");
		break;
	case 5:
		printf("축");
		break;
	case 6:
		printf("인");
		break;
	case 7:
		printf("묘");
		break;
	case 8:
		printf("진");
		break;
	case 9:
		printf("사");
		break;
	case 10:
		printf("오");
		break;
	case 11:
		printf("신");
		break;
	default:
		printf(" 오류입니다. ");
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
		strcpy_s(result1, 3 , "경");
		break;
	case 1:
		strcpy_s(result1,3, "신");
		break;
	case 2:
		strcpy_s(result1,3, "임");
		break;
	case 3:
		strcpy_s(result1,3, "계");
		break;
	case 4:
		strcpy_s(result1,3, "갑");
		break;
	case 5:
		strcpy_s(result1,3, "을");
		break;
	case 6:
		strcpy_s(result1,3, "병");
		break;
	case 7:
		strcpy_s(result1,3, "정");
		break;
	case 8:
		strcpy_s(result1,3, "무");
		break;
	case 9:
		strcpy_s(result1,3, "기");
		break;
	default:
		printf("오류입니다. ");

	}
	switch (b)
	{
	case 0:
		strcpy_s(result2,3, "신");
		break;
	case 1:
		strcpy_s(result2,3, "유");
		break;
	case 2:
		strcpy_s(result2,3, "술");
		break;
	case 3:
		strcpy_s(result2,3, "해");
		break;
	case 4:
		strcpy_s(result2,3, "자");
		break;
	case 5:
		strcpy_s(result2,3, "축");
		break;
	case 6:
		strcpy_s(result2,3, "인");
		break;
	case 7:
		strcpy_s(result2,3, "묘");
		break;
	case 8:
		strcpy_s(result2,3, "진");
		break;
	case 9:
		strcpy_s(result2,3, "사");
		break;
	case 10:
		strcpy_s(result2,3, "오");
		break;
	case 11:
		strcpy_s(result2,3, "미");
		break;
	default:
		printf(" 오류입니다. ");
	}
	return result1;
}

int main()
{
	//1
	printf("내가 태어난 연도는? ");
	int year;
	scanf_s("%d", &year);
	printf("%s\n",animal(year));
	
	//printf("%s\n", q2(year));

	//2
	printf("태어난 연도 다시 입력 ");
	scanf_s("%d", &year);
	int a = year % 10;
	int b = year % 12;
	switch (a)
	{
	case 0:
		printf("경");
		break;
	case 1:
		printf("신");
		break;
	case 2:
		printf("임");
		break;
	case 3:
		printf("계");
		break;
	case 4:
		printf("갑");
		break;
	case 5:
		printf("을");
		break;
	case 6:
		printf("병");
		break;
	case 7:
		printf("정");
		break;
	case 8:
		printf("무");
		break;
	case 9:
		printf("기");
		break;
	default :
		printf("오류입니다. ");

	}
	switch (b)
	{
	case 0:
		printf("신");
		break;
	case 1:
		printf("유");
		break;
	case 2:
		printf("술");
		break;
	case 3:
		printf("해");
		break;
	case 4:
		printf("자");
		break;
	case 5:
		printf("축");
		break;
	case 6:
		printf("인");
		break;
	case 7:
		printf("묘");
		break;
	case 8:
		printf("진");
		break;
	case 9:
		printf("사");
		break;
	case 10:
		printf("오");
		break;
	case 11:
		printf("신");
		break;
	default:
		printf(" 오류입니다. ");
	}
	printf("\n\n");
	printf("태어난 연도 다시 입력 ");
	scanf_s("%d", &year);
	
	//2-1
	q2(year);

	//2-2
	printf("\n태어난 연도 다시 입력 ");
	scanf_s("%d", &year);
	printf("%s", qq2(year));


	
	return 0;
}