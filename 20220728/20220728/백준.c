#include<stdio.h>
int main()
{
	//���� 2420
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (b > a)
		printf("%lld", b - a);
	else
		printf("%lld", a - b);
	//ll �� ���� ���̴� ������ �Է¹����� �� ���ƾ� �Ѵ�.
	// -20�￡�� 20���� ���̴� �ִ� 40������ 
	//int���� ������ ����� ������ ��갪�� longlongint�� �̿��ؾ� �Ѵ�.

	return 0;
}