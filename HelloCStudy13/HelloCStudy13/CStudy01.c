#include<stdio.h>
struct Student
{
	char name[100]; //학생이름
	int number; //학생번호

}typedef Student;

int main()
{
	Student s1 = { .number = 1, .name = "도광현" };
	printf("%s %d\n", s1.name, s1.number);
	Student ss[3];
	ss[0] = (Student){ .number = 2, .name = "김진규" };
	printf("학생의 이름은? ");
	gets(ss[1].name);
	printf("학생의 번호는? ");
	scanf_s("%d", &ss[1].number);
	ss[2].number = 10;
	strcpy(ss[2].name, "최호준");	//string copy
	printf("%s %d\n", ss[1].name, ss[1].number);
	printf("%s %d\n", ss[2].name, ss[2].number);
}