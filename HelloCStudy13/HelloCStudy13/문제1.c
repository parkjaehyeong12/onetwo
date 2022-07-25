#include<stdio.h>
struct Student
{
	char name[100]; //학생이름
	char number[100]; //학생번호

}typedef Student;

void one(Student a)
{
	printf("%s %s\n", a.number, a. name);
	
}
int main()
{
	//1번
	one();

	/*
	ss[0] = (Student){ .number = 0, .name = "김진규" };
	for (int i = 1; i <=3 ; i++)
	{
		printf("학생의 이름은? ");
		gets(ss[i].name);
		printf("학생의 번호는? ");
		scanf_s("%d", &ss[i].number);
		rewind(stdin);
	}
	strcpy(ss[1].name, "최호준");
	printf("%s %d\n", ss[1].name, ss[1].number);
	/*
	for (int i = 0; i <= 3; i++)
	{
		printf("%s %d\n", ss[i].name, ss[i].number);
	}*/

	//2
	ss[10];
	for (int i = 0; i <= 20; i++)
	{
		int n;
		scanf_s("%d", &n);
		if (ss[n] != NULL)
		{

		}
	}



	return 0;
}