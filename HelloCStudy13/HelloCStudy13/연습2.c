#include<stdio.h>
struct Student
{
	int number;
	char name[100];
}typedef stu; //'�̸�'�̶�� ����

void printStudent(stu s)
{
	printf("%d�� �л� %s", s.number, s.name);
}

int main()
{
	stu student[20]; //�迭���� //���� 20��, ���� 20��

	for (int i = 0; i < 5; i++)
	{
		int temp;
		printf("�л��� ��ȣ? ");  //1 ��ȣ����
		scanf_s("%d", &temp);
		int dupli = 0; //��� ����� ���θ� üũ�ϰ� ǥ��

		for (int j = 0; j < i; j++)//0, 0�� �� �н��ϰ� ����
		{
			if (student[j].number == temp) //3 ��ġ�°� break
			{
				printf("�ߺ�\n");
				i--;

				dupli = 1;
				break;
			}
		}
		if (dupli == 0)
		{
			student[i].number = temp;  //2 �Ȱ�ġ�� ����
			printf("�̸���? ");         //�׸��� �̸� �Է¹ް� ����
			
			rewind(stdin);             //�����Է� �ް� �����Է�
			gets(student[i].name);
		}
	}
	for (int i = 0; i < 5; i++)
		printStudent(student[i]);

	return 0;
}