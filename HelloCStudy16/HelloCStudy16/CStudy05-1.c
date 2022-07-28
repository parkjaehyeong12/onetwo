#include<stdio.h>
//실습 3번
struct xy2
{
	int x;
	int y;
}typedef xy2;

struct xyz3
{
	int x;
	int y;
	int z;
}typedef xyz3;

struct animal
{
	char bear[100];
	char tiger[100];
	char eagle[100];
}typedef animal;

struct baseball
{
	char one[20];
	char two[20];
	char three[20];
	char four[20];
	char five[20];
	char six[20];
	char seven[20];
	char eight[20];
	char nine[20];
}typedef base;

void kbo(base doosan)
{
	printf("%s\n", doosan.nine);
}

char* kbo2(base samsung)
{
	printf("%s\n", samsung.eight);
	return samsung.one;
}

int main()
{
	xy2 game1 = { .x = 1, .y = 2 };
	xy2 game2 = { .x = 15, .y = 20 };

	xyz3 game3 = { .x = 1, .y = 2, .z = 3 };
	xyz3 game4 = { .x = 45, .y = 64, .z = 77 };

	animal seoul = { "반달곰","시베리아 호랑이","대머리독수리" };
	animal daegu = { "흑곰", "벵골호랑이", "검독수리" };

	base samsung = { "김현준", "피렐라", "구자욱", "오재일", "강민호", "김태군", "김헌곤", "이원석", "오선진" };
	base doosan = { "정수빈", "페르난데스", "양석환", "김재환", "양찬열", "안재석", "허경민", "박세혁", "김재호" };

	//선수교체 뭐 대타?
#pragma region 야구
	strcpy(samsung.nine, "이재현");
	strcpy(doosan.three, "박계범");
	printf("대타 1 ");
	gets(samsung.three);
	rewind(stdin);
	printf("대타 2 ");
	gets(samsung.four);
	printf("%s\n\n", samsung.four);
	printf("삼성 라이온즈 라인업\n");
	printf("1번타자 %s\n", samsung.one);
	printf("2번타자 %s\n", samsung.two);
	printf("3번타자 %s\n", samsung.three);
	printf("4번타자 %s\n", samsung.four);
	printf("5번타자 %s\n", samsung.five);
	printf("6번타자 %s\n", samsung.six);
	printf("7번타자 %s\n", samsung.seven);
	printf("8번타자 %s\n", samsung.eight);
	printf("9번타자 %s\n", samsung.nine);

	kbo(doosan);
	printf("%s\n", kbo2(samsung));
#pragma endregion


	return 0;
}