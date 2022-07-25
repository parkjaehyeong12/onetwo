#include<stdio.h>
struct Student  //광현이형 거
{
	int number;
	char name[20];
}typedef stu;

//1
void one(stu a)
{
	printf("%d %s\n", a.number, a.name);

}

int main()
{
	stu class[20] = { NULL };
	int n;
		for (int i = 0; i < 5; i++)
		{
			for (;;)
			{
				printf("번호를 입력해주세요 ");
				scanf_s("%d", &n);
				if (class[n].number == NULL)
				{
					class[n].number = n;
					break; //break는 for문 하나만 탈출
				}
				printf("중복된 숫자입니다 다시 입력해주세요\n");
			}
			rewind(stdin);
			printf("이름을 입력해주세요");
			gets(class[n].name);
		}
		//3번
		for (int i = 0; i < 5; i++)
		{
			one(class[i]);
		}
		
}
