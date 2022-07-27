#include<stdio.h>

int main()
{
	int month;
	printf("q1 태어난 달을 입력 ");
	scanf_s("%d", &month);
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

	
	switch (month)
	{
	case 6:
		printf("여름\n");
		break;
	default:
		break;
	}

	return 0;
}