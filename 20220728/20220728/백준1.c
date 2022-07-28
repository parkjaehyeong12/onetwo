#include<stdio.h> //10818
int main()
{
	int n, some;
	scanf_s("%d", &n);
	char arr[100];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &some);
		arr[i] = some;
	}
	int what = arr[0];
	for (int j = 1; j < n; j++)
	{
		if (what > arr[j])
		{
			int temp = what;
			what = arr[j];
			arr[j] = temp;
		}
	}
	printf("%d ", what);
	for (int k = 1; k < n; k++)
	{
		if (what < arr[k])
		{
			int temp = what;
			what = arr[k];
			arr[k] = temp;
		}
	}
	printf("%d", what);

	return 0;
}