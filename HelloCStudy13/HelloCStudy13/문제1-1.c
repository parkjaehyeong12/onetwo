#include<stdio.h>
struct Student  //�������� ��
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
				printf("��ȣ�� �Է����ּ��� ");
				scanf_s("%d", &n);
				if (class[n].number == NULL)
				{
					class[n].number = n;
					break; //break�� for�� �ϳ��� Ż��
				}
				printf("�ߺ��� �����Դϴ� �ٽ� �Է����ּ���\n");
			}
			rewind(stdin);
			printf("�̸��� �Է����ּ���");
			gets(class[n].name);
		}
		//3��
		for (int i = 0; i < 5; i++)
		{
			one(class[i]);
		}
		
}
