#include<stdio.h>
int ten(int n)
{
	int t0 = 0, t1 = 1;
	int next = t0 + t1;
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", t1);
		t0 = t1;
		t1 = next;
		next = t0 + t1;
	}
	return 0;
}

int main()
{
	int n;
	printf("몇 열까지? ");
	scanf_s("%d", &n);
	ten(n);
	return 0;
}