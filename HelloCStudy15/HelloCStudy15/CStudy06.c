#include<stdio.h>
void printYourname(char n[]) // (char* n)
{
	printf("����� �̸��� %s�Դϴ�.\n",n);
}

char* printfABC() // ~ ������ �Է�
{
	return "abc\n";
}

//�Ű����� ���� ���ڿ��� �Է¹޾Ƽ� ����?
char* returnMyinfo()
{
	static char mbti[5];
	//��� ���ڿ��� �Է��ؼ� ���������� ������ static�� ������

	//static�� ���̸� �ȴ�. �׳��� �����Ⱚ
	//static�� �����Ϳ� ������ ���Ѽ�
	//��ȭ�� ��Ű�� �ʴ´�.
	//int �� �ȴ�.
	//�׷��� char�� ������� mbti�� �ּҰ��̱� ������
	//static���� ������������ ������ ��ȭ�ȴ�. �̻��ϰ�

	//mbti�� �������̱� ������ �Լ��� ������ ������� �ȴ�.
	//static���� mbti�� ���ÿ����� �ƴ� �����Ϳ����� �Ҵ��ϰ� �Ǹ�
	//������� �ʰ� �ȴ�.

	//���� ����ƽ�� �� ����ϰ������ �׳� ū ���ڸ� ������ �ȴ�.
	//150�̳� 1024����?
	

	printf("mbti? ");
	gets(mbti);

	return mbti;
}
char* change(char n[])
{
	printf("�ٲ� �� ����غ���");
	//rewind(stdin);
	gets(n);
	return n;
}

char* returnMymbti(char* mbti)
{
	return mbti;
	
	// ���ʿ� ���� �ȿ� �ִ� �����Ͱ� ��򰡸�
	//����Ű�� �װ��� �� �Լ��� �׳� ����ٰ� ���� ���̴�.
	//�׷��� ������ ������� �ʴ� ���̴�.


}


int main()
{
	printf("�̸� �Է� ");
	char name[100]; //���ڹ迭
	gets(name);
	printYourname(name); //���ڹ迭�� ���ڿ�

	printf("%s", printfABC()); //���ڿ��� �����ϴ� �͵� ����

	rewind(stdin);

	//�迭�� ������, name�迭�� name�����Ͷ�� ���� �ȴ�.
	
	printf("%s\n",returnMyinfo());
	
	printf("%s\n", returnMymbti("ESTP"));

	char mbti[5];
	gets(mbti);
	printf("%s\n",returnMymbti(mbti));
	printf("%s\n", change(name));
	/*
	�Լ� �ȿ��� �Է¹��� ���ڿ��� �����Ⱚ�� ������
	�Ű������� �� ���ڿ��� ���� ��������.



	*/




	return 0;
}