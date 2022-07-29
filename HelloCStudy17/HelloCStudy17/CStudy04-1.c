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
	printf("첫번째 학생의 C점수와 자바 점수는? ");
	scanf_s("%d %d", &s1.cScore, &s1.javaScore);
	printf("학생의 이름은? ");
	rewind(stdin);
	gets(s1.name);

	//3
	KBStudent s2, s3, s4, s5;
	printf("두번째 학생의 C점수와 자바 점수는? ");
	scanf_s("%d %d", &s2.cScore, &s2.javaScore);
	printf("학생의 이름은? ");
	rewind(stdin);
	gets(s2.name);
	printf("세번째 학생의 C점수와 자바 점수는? ");
	scanf_s("%d %d", &s3.cScore, &s3.javaScore);
	printf("학생의 이름은? ");
	rewind(stdin);
	gets(s3.name);
	printf("네번째 학생의 C점수와 자바 점수는? ");
	scanf_s("%d %d", &s4.cScore, &s4.javaScore);
	printf("학생의 이름은? ");
	rewind(stdin);
	gets(s4.name);
	printf("다번째 학생의 C점수와 자바 점수는? ");
	scanf_s("%d %d", &s5.cScore, &s5.javaScore);
	printf("학생의 이름은? ");
	rewind(stdin);
	gets(s5.name);

	printf("\----------------입력 끝---------------------\n");

	printf("c 점수의 합은 %d\n",
		s1.cScore + s2.cScore + s3.cScore + s4.cScore + s5.cScore);
	printf("자바 점수의 합은 %d\n",
		s1.javaScore + s2.javaScore + s3.javaScore + s4.javaScore + s5.javaScore);
	//4
	printf("c 평균 점수는 %d\n", (s1.cScore + s2.cScore + s3.cScore + s4.cScore + s5.cScore) / 5);
	//5
	printf("자바 평균 점수는 %d\n", (s1.javaScore + s2.javaScore + s3.javaScore + s4.javaScore + s5.javaScore)/ 5);

	//6번 1등 구하기 //최대값 가진 학생 구하기. 학생수보다 1번 적게 실행

	// 뭐가 잘못된 것인지 복기해보기

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
	printf("C점수 1등은 s%d 학생입니다.",&k);

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
	printf("C점수 꼴등은 s%d 학생입니다.", &k);

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
	printf("자바점수 1등은 s%d 학생입니다.", &k);

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
	printf("자바점수 꼴등은 s%d 학생입니다.", &k);

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