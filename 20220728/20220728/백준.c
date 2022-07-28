#include<stdio.h>
int main()
{
	//백준 2420
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (b > a)
		printf("%lld", b - a);
	else
		printf("%lld", a - b);
	//ll 을 굳이 붙이는 이유는 입력범위를 잘 보아야 한다.
	// -20억에서 20억의 차이는 최대 40억으로 
	//int형의 범위를 벗어나기 때문에 계산값은 longlongint를 이용해야 한다.

	return 0;
}