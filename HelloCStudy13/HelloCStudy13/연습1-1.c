#include<stdio.h>
struct Score
{
	int kor;
	int mat; //���м���
	int eng; //�����
}typedef Score;

int main()
{
	 Score s = { 100,90,80 };
     Score* p = NULL;

	p = &s;

	printf("����ü s�� �ּҰ� : %p\n", s);
	printf("���� : %d ���� : %d ���� : %d \n", s.kor, s.mat, s.eng);
	printf("���� : %d ���� : %d ���� : %d \n", (*p).kor, (*p).mat, (*p).eng);
	printf("���� : %d ���� : %d ���� : %d \n", p->kor, p->mat, p->eng);

	/*
	   ����ü�� ���������� �ּҰ��� �ִ�.
	   ���� ����ó�� %p �� ����ü�� Ȯ���غ��� �ּ� ���� Ȯ���� �� �ִ�.
	   ����ü ������ �����͸� ����Ѵٴ� �ǹ̴� ����ü������ ���� ������ ��
	   �ִٴ� �ǹ�.

	   https://coding-factory.tistory.com/640
	*/

	return 0;
}