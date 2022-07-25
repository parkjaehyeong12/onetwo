#include<stdio.h>
struct Student
{
	int number;
	char name[100];
}typedef stu; //'이명'이라고 본다

void printStudent(stu s)
{
	printf("%d번 학생 %s", s.number, s.name);
}

int main()
{
	stu student[20]; //배열생성 //숫자 20열, 문자 20열

	for (int i = 0; i < 5; i++)
	{
		int temp;
		printf("학생의 번호? ");  //1 번호지정
		scanf_s("%d", &temp);
		int dupli = 0; //통과 비통과 여부를 체크하고 표시

		for (int j = 0; j < i; j++)//0, 0일 땐 패스하고 저장
		{
			if (student[j].number == temp) //3 겹치는거 break
			{
				printf("중복\n");
				i--;

				dupli = 1;
				break;
			}
		}
		if (dupli == 0)
		{
			student[i].number = temp;  //2 안겹치면 저장
			printf("이름은? ");         //그리고 이름 입력받고 저장
			
			rewind(stdin);             //숫자입력 받고 문자입력
			gets(student[i].name);
		}
	}
	for (int i = 0; i < 5; i++)
		printStudent(student[i]);

	return 0;
}