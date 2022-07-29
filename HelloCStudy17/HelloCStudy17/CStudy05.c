#include<stdio.h>
#include"Mystructs.h"
int main()
{
	if (0)
	{
		//학생 1명 만들어보기(대입) - 1
		KBStudent k1 = { 100,90,"이동준" };

		//학생 1명 만들어보기(대입) - 2
		KBStudent k2 = { .cScore = 100, .javaScore = 100, .name = "이유나선생님" };

		//학생 1명 만들어보기(대입) - 3
		KBStudent k3;
		k3.cScore = 100;
		k3.javaScore = 0;
		strcpy(k3.name, "김동준");

		//학생 1명 만들어보기(입력)
		KBStudent k4;
		scanf_s("%d %d", &k4.cScore, &k4.javaScore);
		rewind(stdin);

		gets(k4.name);
		printf("%d %d %s", k4.cScore, k4.javaScore, k4.name);
		//최대 최소구하는 것도 있어서
		//배열로 해야 한다.
	}

	KBStudent students[5];

	int cSum = 0;
	int javaSum = 0;
	double cAvg, javaAvg;
	int maxC = 0;
	int maxjava = 0;
	double avg_max = 0;
	double avg_min = 0;
	int index_max = 0; //1등 인덱스 평균
	int index_max_C = 0; //1등 인덱스(c)
	int index_max_Java = 0; //1등 인덱스(java)

	for (int i = 0; i < 5; i++)
	{
		rewind(stdin);
		printf("\n이름이 뭔가요? ");
		gets(students[i].name);
		printf("C점수 자바 점수는? ");
		scanf_s("%d %d", &students[i].cScore, &students[i].javaScore);
	}

	for (int i = 0; i < 5; i++)
	{
		cSum += students[i].cScore;
		javaSum += students[i].javaScore;
	}
	printf("\nc,java 각각의 총합 %d %d\n", cSum, javaSum);
	printf("c,java 각각의 평균 %f %f\n", cSum / 5.0, javaSum / 5.0);

	maxC = students[0].cScore;
	maxjava = students[0].javaScore;
	avg_max = (students[0].cScore+ students[0].javaScore)/2.0;

	for (int i = 0; i < 5; i++)
	{
		if (maxC < students[i].cScore)
		{
			maxC = students[i].cScore;
			index_max_C = i;
		 }
		if (maxjava < students[i].javaScore)
		{
			maxjava = students[i].javaScore;
			index_max_Java = i;
		}
		if (avg_max < (students[i].cScore + students[i].javaScore) / 2.0)
		{
			avg_max = (students[i].cScore + students[i].javaScore) / 2.0;
			index_max = i;
		}
	}
	printf("C 1등 : %s\n", students[index_max_C].name);
	printf("Java 1등 : %s\n", students[index_max_Java].name);
	printf("평균 1등 : %s\n", students[index_max].name);






	return 0;
}