#include<stdio.h>
//�ǽ� 2 Ǯ��
int main()
{
	int counts[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("���ǽ� �� �л��� �Է� ");
			scanf_s("%d", &counts[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t",counts[i][j]); // \t�� ��Ű�� 4ĭ���� �����ڴ�. 
		}
		printf("\n");
	}

	//3�� ����ũ����
	//�ؼ�1 counts[0] ~counts[i-1]��° ���� �����ͼ� ����.
	//�ؼ�2 �׳� 1���� �迭 ����� �� �ȿ� �� �ִ´�.
	
	int rooms[3]; //3��
    //�� �ε����� ���� ������ �װ� �ٷ� �� ���� ���ǽ� ����
	scanf_s("%d %d %d", &rooms[0], &rooms[1], &rooms[2]);
	printf("%d %d %d", rooms[0], rooms[1], rooms[2]);


	return 0;
}