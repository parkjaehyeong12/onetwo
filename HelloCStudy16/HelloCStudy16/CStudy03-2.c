#include<stdio.h>
int main()
{
	//1 �б� ���� ���ǽ� ������ ����� �л��� �� �����غ��� //3�� 4���ǽ� ������ �л��� ��
	int stu[3][4] = {
		{25,30,13,14},
		{16,19,24,29},
		{25,23,31,15}
	};

	//2
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d �� % d���ǽ� �л��� %d ���̴�.\n", i + 1, ((i+1)*100)+(j + 1), stu[i][j]);
	}

	printf("\n");

	//3
	printf("�� ��? ���ǽ� �? ");
	int floor, room, num;
	scanf_s("%d %d", &floor, &room);

	int students[100][100];
	printf("\n");

	for (int i = 0; i < floor; i++)
	{
		printf("%d ��\n", i + 1);
		for (int j = 0; j < room; j++)
		{ 
			printf("%d ���ǽ� : ",((i+1)*100)+j+1);
			scanf_s("%d", &num);
			students[i][j] = num;
		}
		printf("\n");
	}
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < room; j++)
		{
			printf("%d���� %d���ǽǿ��� %d���� �л��� �ִ�.\n", i + 1, ((i + 1) * 100)+j + 1, students[i][j]);
		}
	}

	


	return 0;
}