#pragma once

//��������
//������ �̸�, ������ ����, ���� ���� �ڵ�
//�ǻ߶�� ���� 2���� �̻��� �� ������
//���� �����ڵ�� ������ ��


//���� ����� ������

struct MyStruct
{
	char name[100];
	char species[100];
	char code[100];
	//���� int Ÿ���ε� 00007������ 7Ȥ�� ������ ���� �� �� �ִ�.

}typedef Animal;

struct Food
{
	int price;
	char name[100];
}typedef Food;

struct StudentScore
{
	int kor;
	int eng;
	int math;
}typedef StudentScore;

struct KBstudent
{
	int cScore;
	int javaScore;
	char name[100];
}typedef KBStudent;