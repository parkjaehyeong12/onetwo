#include <stdio.h>
//���� 5597
int main()
{
	int arr[31] = { 1,0, }; // 0���� �����Ƿ� 1�� �ʱ�ȭ
	int tmp;
	for (int i = 0; i < 28; i++)
	{
		scanf_s("%d", &tmp);
		arr[tmp] = 1;
	}

	//�迭�� �� [i] ��°�� i�� �� �˻��ϰ��� �ϴ� �����ϼ��� �ִ�.
	//�ٵ� ���� ��� �� ���� ��ü�� �ΰ� �˻縦 �ٽ� �Ϸ��� �ȵǴ±���


	printf("\n");
	for (int i = 0; i < 31; i++)
		if (arr[i] == 0)
			printf("%d\n", i);
	return 0;
}
