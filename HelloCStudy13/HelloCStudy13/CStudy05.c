//������
//�������ּҸ� �����ϴ� Ÿ��

#include<stdio.h>

void changeValue(int* p, int v)
{
	*p = v; //p������ �ִ� ���� v�� �ٲ۴ٴ� �ǹ�
}//*p �� �ּҰ� ����Ű�� ���� ���� ����Ų�ٴ� ��
//p�� ���شٸ� p���� �ٲ���� ���ο� �ִ� ���� ���� �ٲ��� ����

void no_changeValue(int p, int v)
{ // �� �Լ� �ȿ� �ִ� ���� �ٲ����� main�̳�
  //�� �Լ��� ȣ���� �κ��� ������ �״���̴�.
	
	p = v; //�ּҸ� ȣ������ �ʴ´ٸ� ���ΰ��� ������ ����

}

int main()
{
	int ex = 10;
	int* exptr = &ex;
	//int*�� int Ÿ�� ������ ��ġ�� ����
	//�Լ��� �Ű������� �ַ� ����, scanf, swap�Լ� ��...

	
	changeValue(exptr, 100);

	printf("ex = %d\n", ex);
	
	changeValue(&ex, 500);
	
	printf("ex = %d\n", ex);
	
	/*
	no_changeValue(ex, 500);

	printf("ex = %d\n", ex);*/




	return 0;
}