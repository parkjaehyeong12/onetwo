#include<stdio.h>
struct Student
{
	int num;
	int score;
	
}typedef Student;

int main()
{
	Student s1 = { 1,50 }; //s1.num = 1, s1.score = 50 �̴�
	Student s2 = { .num = 2, 60 };
	Student s3;
	s3.num = 3;
	s3.score = 70; //�ε��������� ���� �Ӽ��� �ִ�.

	return 0;
}