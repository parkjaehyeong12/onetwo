#include<stdio.h>
struct Score
{
	//��� ������ ������ ����ϱ�

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

	printf("�������� : %d\n", *s.kor);   //100
	printf("�������� : %d\n", *s.math);  //90
	printf("�������� : %d\n\n", *s.eng); // 80

	score1 = 50;
	score2 = 40;
	score3 = 30;

	printf("�������� : %d\n", *s.kor);  //50
	printf("�������� : %d\n", *s.math); //40
	printf("�������� : %d\n", *s.eng);  //30

	/* ����ü�� ����� �����͸� ������ �� �پ��ϰ� ����� �� �ִ�.
	����� ����ü ���� �����͵��� �������� �ּҸ� ������ �� ������
	�����Ͱ� �� �������� �ּҰ��� ����Ű�� �����Ƿ� �� ������ ������ �ٲ� ��
	���������� ���� �ٲ�� ��ü���� ������ �� �ְ� �ȴ�.
	*/

	return 0;

}