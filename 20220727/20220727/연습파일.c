#include <stdio.h>    // scanf, printf

int main()
{
    char* gan_s[] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };
    char* jee_s[] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };


    int west, gan, jee, dangui;    // 2017 ������

//  while (1) {
    printf("���⿬�� :  ");
    scanf_s("%d", &west);

    gan = west % 10 + 6;
    jee = west % 12 + 8;

    if (gan > 9) gan -= 10;
    if (jee > 11) jee -= 12;

    dangui = west + 2333;

    printf("���� %d (�ܱ� : %d) : %s%s��\n", west, dangui, gan_s[gan], jee_s[jee]);
    //  }

    return 0;
}
