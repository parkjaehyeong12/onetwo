#include<stdio.h>
//�ǽ� 3��
struct xy2
{
	int x;
	int y;
}typedef xy2;

struct xyz3
{
	int x;
	int y;
	int z;
}typedef xyz3;

struct animal
{
	char bear[100];
	char tiger[100];
	char eagle[100];
}typedef animal;

struct baseball
{
	char one[20];
	char two[20];
	char three[20];
	char four[20];
	char five[20];
	char six[20];
	char seven[20];
	char eight[20];
	char nine[20];
}typedef base;

void kbo(base doosan)
{
	printf("%s\n", doosan.nine);
}

char* kbo2(base samsung)
{
	printf("%s\n", samsung.eight);
	return samsung.one;
}

int main()
{
	xy2 game1 = { .x = 1, .y = 2 };
	xy2 game2 = { .x = 15, .y = 20 };

	xyz3 game3 = { .x = 1, .y = 2, .z = 3 };
	xyz3 game4 = { .x = 45, .y = 64, .z = 77 };

	animal seoul = { "�ݴް�","�ú����� ȣ����","��Ӹ�������" };
	animal daegu = { "���", "����ȣ����", "�˵�����" };

	base samsung = { "������", "�Ƿ���", "���ڿ�", "������", "����ȣ", "���±�", "�����", "�̿���", "������" };
	base doosan = { "������", "�丣������", "�缮ȯ", "����ȯ", "������", "���缮", "����", "�ڼ���", "����ȣ" };

	//������ü �� ��Ÿ?
#pragma region �߱�
	strcpy(samsung.nine, "������");
	strcpy(doosan.three, "�ڰ��");
	printf("��Ÿ 1 ");
	gets(samsung.three);
	rewind(stdin);
	printf("��Ÿ 2 ");
	gets(samsung.four);
	printf("%s\n\n", samsung.four);
	printf("�Ｚ ���̿��� ���ξ�\n");
	printf("1��Ÿ�� %s\n", samsung.one);
	printf("2��Ÿ�� %s\n", samsung.two);
	printf("3��Ÿ�� %s\n", samsung.three);
	printf("4��Ÿ�� %s\n", samsung.four);
	printf("5��Ÿ�� %s\n", samsung.five);
	printf("6��Ÿ�� %s\n", samsung.six);
	printf("7��Ÿ�� %s\n", samsung.seven);
	printf("8��Ÿ�� %s\n", samsung.eight);
	printf("9��Ÿ�� %s\n", samsung.nine);

	kbo(doosan);
	printf("%s\n", kbo2(samsung));
#pragma endregion


	return 0;
}