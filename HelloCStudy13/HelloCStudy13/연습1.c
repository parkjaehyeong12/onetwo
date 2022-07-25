#include<stdio.h>
struct Score
{
	//멤버 변수로 포인터 사용하기

	int* kor;
	int* math;
	int* eng;


}typedef sco;

int main()
{
	int score1 = 100;
	int score2 = 90;
	int score3 = 80;

	sco s;
	s.kor = &score1;
	s.math = &score2;
	s.eng = &score3;

	printf("국어점수 : %d\n", *s.kor);   //100
	printf("수학점수 : %d\n", *s.math);  //90
	printf("영어점수 : %d\n\n", *s.eng); // 80

	score1 = 50;
	score2 = 40;
	score3 = 30;

	printf("국어점수 : %d\n", *s.kor);  //50
	printf("수학점수 : %d\n", *s.math); //40
	printf("영어점수 : %d\n", *s.eng);  //30

	/* 구조체의 멤버에 포인터를 선언한 후 다양하게 사용할 수 있다.
	선언된 구조체 안의 포인터들은 변수들의 주소를 저장할 수 있으며
	포인터가 그 변수들의 주소값을 가리키고 있으므로 그 변수의 값들이 바뀔 때
	유동적으로 값이 바뀌는 객체들을 생성할 수 있게 된다.
	*/

	return 0;

}