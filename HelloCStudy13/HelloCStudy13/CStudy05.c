//포인터
//변수의주소를 저장하는 타입

#include<stdio.h>

void changeValue(int* p, int v)
{
	*p = v; //p가지고 있는 것을 v로 바꾼다는 의미
}//*p 는 주소가 가리키는 값을 직접 가리킨다는 것
//p만 써준다면 p값은 바뀌더라도 메인에 있는 값은 절대 바뀌지 않음

void no_changeValue(int p, int v)
{ // 이 함수 안에 있는 값은 바뀌지만 main이나
  //이 함수를 호출한 부분의 변수는 그대로이다.
	
	p = v; //주소를 호출하지 않는다면 메인과는 완전히 남남

}

int main()
{
	int ex = 10;
	int* exptr = &ex;
	//int*는 int 타입 변수의 위치를 저장
	//함수의 매개변수로 주로 쓰임, scanf, swap함수 등...

	
	changeValue(exptr, 100);

	printf("ex = %d\n", ex);
	
	changeValue(&ex, 500);
	
	printf("ex = %d\n", ex);
	
	/*
	no_changeValue(ex, 500);

	printf("ex = %d\n", ex);*/




	return 0;
}