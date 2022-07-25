#include<stdio.h>
struct parkjaehyeongscore
{
	int kor;
	int math;
	int eng;

}typedef pjh;



int main()
{
	pjh score;
	score.kor = 100;
	score.math = 80;
	score.eng = 60;
	printf("%d", (score.kor + score.math + score.eng) / 3);

	

	return 0;
}