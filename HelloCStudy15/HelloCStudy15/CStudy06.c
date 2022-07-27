#include<stdio.h>
void printYourname(char n[]) // (char* n)
{
	printf("당신의 이름은 %s입니다.\n",n);
}

char* printfABC() // ~ 형으로 입려
{
	return "abc\n";
}

//매개변수 없이 문자열을 입력받아서 리턴?
char* returnMyinfo()
{
	static char mbti[5];
	//결론 문자열을 입력해서 돌려보내고 싶으면 static을 적을것

	//static을 붙이면 된다. 그냥은 쓰레기값
	//static은 데이터에 저장을 시켜서
	//변화를 시키지 않는다.
	//int 는 된다.
	//그러나 char로 만들어진 mbti는 주소값이기 때문에
	//static으로 고정시켜주지 않으면 변화된다. 이상하게

	//mbti는 포인터이기 때문에 함수가 끝나면 사라지게 된다.
	//static으로 mbti를 스택영역이 아닌 데이터영역에 할당하게 되면
	//사라지지 않게 된다.

	//만약 스테틱을 안 사용하고싶으면 그냥 큰 숫자를 넣으면 된다.
	//150이나 1024같은?
	

	printf("mbti? ");
	gets(mbti);

	return mbti;
}
char* change(char n[])
{
	printf("바뀐 값 출력해보기");
	//rewind(stdin);
	gets(n);
	return n;
}

char* returnMymbti(char* mbti)
{
	return mbti;
	
	// 애초에 메인 안에 있는 포인터가 어딘가를
	//가리키고 그것을 이 함수가 그냥 끌어다가 쓰는 것이다.
	//그렇기 때문에 사라지지 않는 것이다.


}


int main()
{
	printf("이름 입력 ");
	char name[100]; //문자배열
	gets(name);
	printYourname(name); //문자배열은 문자열

	printf("%s", printfABC()); //문자열을 리턴하는 것도 가능

	rewind(stdin);

	//배열은 포인터, name배열은 name포인터라고 봐도 된다.
	
	printf("%s\n",returnMyinfo());
	
	printf("%s\n", returnMymbti("ESTP"));

	char mbti[5];
	gets(mbti);
	printf("%s\n",returnMymbti(mbti));
	printf("%s\n", change(name));
	/*
	함수 안에서 입력받은 문자열은 쓰레기값이 나오고
	매개변수로 들어간 문자열은 값이 나오ㄴ다.



	*/




	return 0;
}