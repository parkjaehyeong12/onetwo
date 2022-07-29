#include <stdio.h>
//백준 5597
int main()
{
	int arr[31] = { 1,0, }; // 0번은 없으므로 1로 초기화
	int tmp;
	for (int i = 0; i < 28; i++)
	{
		scanf_s("%d", &tmp);
		arr[tmp] = 1;
	}

	//배열의 각 [i] 번째의 i가 곧 검사하고자 하는 숫자일수가 있다.
	//근데 나는 계속 각 줄을 전체로 두고 검사를 다시 하려니 안되는구나


	printf("\n");
	for (int i = 0; i < 31; i++)
		if (arr[i] == 0)
			printf("%d\n", i);
	return 0;
}
