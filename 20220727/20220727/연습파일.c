#include <stdio.h>    // scanf, printf

int main()
{
    char* gan_s[] = { "갑", "을", "병", "정", "무", "기", "경", "신", "임", "계" };
    char* jee_s[] = { "자", "축", "인", "묘", "진", "사", "오", "미", "신", "유", "술", "해" };


    int west, gan, jee, dangui;    // 2017 정유년

//  while (1) {
    printf("서기연도 :  ");
    scanf_s("%d", &west);

    gan = west % 10 + 6;
    jee = west % 12 + 8;

    if (gan > 9) gan -= 10;
    if (jee > 11) jee -= 12;

    dangui = west + 2333;

    printf("서기 %d (단기 : %d) : %s%s년\n", west, dangui, gan_s[gan], jee_s[jee]);
    //  }

    return 0;
}
