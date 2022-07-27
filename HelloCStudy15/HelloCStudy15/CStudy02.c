#include<stdio.h>
void season()
{
	int month;
	printf("q2 몇월생? ");
	scanf_s("%d", &month);
	if (month == 12 || month == 1 || month == 2)
		printf("겨울\n");
	else if (month >= 3 && month <= 5)
		printf("봄\n");
	else if (month >= 6 && month <= 8)
		printf("여름\n");
	else if (month >= 9 && month <= 11)
		printf("가을\n");
	else
		printf("오류\n");
}
void printSeason(int month)
{
	switch (month)
	{
	case 12:
		month = 6; //여름으로 찍힐까. ()안에 있을 때만 의미가 있더라
	case 1:
	case 2:
		printf("Winter is coming\n");
		break;
	case 3:
	case 4:
	case 5:
		printf("Spring\n");
		break;
	case 6:
	case 7:
	case 8:
		printf("Daegu is coming\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("가을, 프로토스의 계절\n");
	default:
		printf("오류\n");
		break;
	}
}

int main()
{
	//2
	season();

	//3
	int m;
	printf("q3 태어난 달을 입력 ");
	scanf_s("%d", &m);
	printSeason(m);


	return;
}