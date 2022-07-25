#include<stdio.h>
struct Score
{
	int kor;
	int mat; //수학성적
	int eng; //영어성적
}typedef Score;

int main()
{
	 Score s = { 100,90,80 };
     Score* p = NULL;

	p = &s;

	printf("구조체 s의 주소값 : %p\n", s);
	printf("국어 : %d 수학 : %d 영어 : %d \n", s.kor, s.mat, s.eng);
	printf("국어 : %d 수학 : %d 영어 : %d \n", (*p).kor, (*p).mat, (*p).eng);
	printf("국어 : %d 수학 : %d 영어 : %d \n", p->kor, p->mat, p->eng);

	/*
	   구조체도 마찬가지로 주소값이 있다.
	   위의 예제처럼 %p 로 구조체를 확인해보면 주소 값을 확인할 수 있다.
	   구조체 변수로 포인터를 사용한다는 의미는 구조체변수에 간접 접근할 수
	   있다는 의미.

	   https://coding-factory.tistory.com/640
	*/

	return 0;
}