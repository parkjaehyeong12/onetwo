#include<stdio.h>
//1. 2D ���� ĳ���� ��ǥ �����ϴ� ����ü �����
//1���� ������ 1�� �̻��ǰ��� ���� !

struct Game2Dpos
{
	int x;
	int y;
};

int main()
{
	//����ü : struct ��Ʈ��Ʈ
	//����ڰ� ���� ���� �ڷ���
	//ũ�⵵ �پ�, �迭�̶��� �ٸ�
	//�Ѱ��� ������ �������� �Ӽ��� ������.

	struct Game2Dpos p1 = { 10,20 };
	printf("%d\n", sizeof(p1));
	//������ 8
	//4����Ʈ�� �� ������ �� �� ����
	
	struct Game2Dpos p2 = { .x = 10, .y = 20 };
	
	struct Game2Dpos p3;
	p3.x = 10;
	p3.y = 20;
	
	struct Game2Dpos p4;
	scanf_s("%d %d", &p4.x, &p4.y);
	printf("x��ǥ %d, y��ǥ %d\n", p4.x, p4.y);




	return 0;
}