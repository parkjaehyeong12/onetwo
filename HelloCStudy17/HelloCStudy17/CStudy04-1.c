#include<stdio.h>
struct KBStudent
{
	int cScore;
	int javaScore;
	char name[100];
}typedef KBStudent;

int main()
{
	//2
	KBStudent s1;
	printf("ù��° �л��� C������ �ڹ� ������? ");
	scanf_s("%d %d", &s1.cScore, &s1.javaScore);
	printf("�л��� �̸���? ");
	rewind(stdin);
	gets(s1.name);

	//3
	KBStudent s2, s3, s4, s5;
	printf("�ι�° �л��� C������ �ڹ� ������? ");
	scanf_s("%d %d", &s2.cScore, &s2.javaScore);
	printf("�л��� �̸���? ");
	rewind(stdin);
	gets(s2.name);
	printf("����° �л��� C������ �ڹ� ������? ");
	scanf_s("%d %d", &s3.cScore, &s3.javaScore);
	printf("�л��� �̸���? ");
	rewind(stdin);
	gets(s3.name);
	printf("�׹�° �л��� C������ �ڹ� ������? ");
	scanf_s("%d %d", &s4.cScore, &s4.javaScore);
	printf("�л��� �̸���? ");
	rewind(stdin);
	gets(s4.name);
	printf("�ٹ�° �л��� C������ �ڹ� ������? ");
	scanf_s("%d %d", &s5.cScore, &s5.javaScore);
	printf("�л��� �̸���? ");
	rewind(stdin);
	gets(s5.name);

	printf("\----------------�Է� ��---------------------\n");

	printf("c ������ ���� %d\n",
		s1.cScore + s2.cScore + s3.cScore + s4.cScore + s5.cScore);
	printf("�ڹ� ������ ���� %d\n",
		s1.javaScore + s2.javaScore + s3.javaScore + s4.javaScore + s5.javaScore);
	//4
	printf("c ��� ������ %d\n", (s1.cScore + s2.cScore + s3.cScore + s4.cScore + s5.cScore) / 5);
	//5
	printf("�ڹ� ��� ������ %d\n", (s1.javaScore + s2.javaScore + s3.javaScore + s4.javaScore + s5.javaScore)/ 5);

	//6�� 1�� ���ϱ� //�ִ밪 ���� �л� ���ϱ�. �л������� 1�� ���� ����

	// ���� �߸��� ������ �����غ���

	int compareC[5] = { s1.cScore,s2.cScore,s3.cScore,s4.cScore,s5.cScore };
	int comparejava[5] = { s1.javaScore ,s2.javaScore ,s3.javaScore ,s4.javaScore ,s5.javaScore };
	int count = 1;
	int ttt[5] = {1,0};
	for (int i = 1; i < 5; i++) 
	{
		if (compareC[0] < compareC[i])
		{
			int temp = compareC[0];
			compareC[0] = compareC[i];
			compareC[i] = temp;
			ttt[0] = i + 1;
		}
		if (compareC[0] = compareC[i])
		{

		}
	}
	printf("C���� 1���� s%d �л��Դϴ�.",&k);

	k = 1;
	for (int i = 1; i < 5; i++)
	{
		if (compareC[0] > compareC[i])
		{
			int temp = compareC[0];
			compareC[0] = compareC[i];
			compareC[i] = temp;
			k = i + 1;
		}
	}
	printf("C���� �õ��� s%d �л��Դϴ�.", &k);

	k = 1;
	for (int i = 1; i < 5; i++)
	{
		if (comparejava[0] < comparejava[i])
		{
			int temp = comparejava[0];
			comparejava[0] = comparejava[i];
			comparejava[i] = temp;
			k = i + 1;
		}
	}
	printf("�ڹ����� 1���� s%d �л��Դϴ�.", &k);

	k = 1;
	for (int i = 1; i < 5; i++)
	{
		if (comparejava[0] > comparejava[i])
		{
			int temp = comparejava[0];
			comparejava[0] = comparejava[i];
			comparejava[i] = temp;
			k = i + 1;
		}
	}
	printf("�ڹ����� �õ��� s%d �л��Դϴ�.", &k);

	//int s1in[2] = { s1.cScore,s1.javaScore };
	//int s2in[2] = { s2.cScore,s2.javaScore };
	//int s3in[2] = { s3.cScore,s3.javaScore };
	//int s4in[2] = { s4.cScore,s4.javaScore };
	//int s5in[2] = { s5.cScore,s5.javaScore };
	//for (int i = 0; i < 2; i++)
	//{
	//	if()


	//}


	

	return 0;
}