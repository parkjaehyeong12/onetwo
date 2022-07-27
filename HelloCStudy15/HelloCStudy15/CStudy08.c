//1.태어난 연도를 매개변수로 받고 무슨 띠인지
#include<stdio.h>
char* outputThee(int year)
{
	switch (year % 12)
	{
	case 0:
		return "원숭이";
	case 1:
		return "닭";
	case 2:
		return "개";
	case 3:
		return "돼지";
	case 4:
		return "쥐";
	case 5:
		return "소";
	case 6:
		return "호랑이";
	case 7:
		return "토끼";
	case 8:
		return "용";
	case 9:
		return "뱀";
	case 10:
		return "말";
	case 11:
		return "양";
	default:
		return "오류";
	}
}
char* moreEasy(int year)
{
	year %= 12;
	//2차원 배열을 쓴다. //1짜리 서랍칸이라고 생각해볼
	static char thees[12][10]
		= { "원숭이","닭","개","돼지","쥐","소","호랑이","토끼","용","뱀","말","양" };
	return thees[year]; //static 에 저장해놔야 함수가 끝나도, 배열이 남아있는다.
}
int main()
{
	char thee[10];
	int year;
	printf("몇년생? ");
	scanf_s("%d", &year);
	printf("%s\n", outputThee(year));
	printf("%s\n",moreEasy(year));

	return 0;
}