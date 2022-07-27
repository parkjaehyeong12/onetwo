//1.태어난 연도를 매개변수로 받고 무슨 띠인지
#include<stdio.h>

int main()
{
    char thee[10];
    int year;
    printf("몇년생? ");
    scanf_s("%d", &year);
    switch (year%12)
    {
    case 0:     
        strcpy(thee, "원숭이"); //띠에 원숭이란 문자열을 집어넣은 것!
        break;                  //단순히 대입문으로는 안된다.
    case 1:
        strcpy(thee, "닭");
        //thee = 원숭이 라고 하면 띠 시작위치에
        //원숭이라는 값을 넣을려고 하니 안된다.
        break;
    case 2:
        strcpy(thee, "개");
        break;
    case 3:
        strcpy(thee, "돼지");
        break;
    case 4:
        strcpy(thee, "쥐");
        break;
    case 5:
        strcpy(thee, "소");
        break;
    case 6:
        strcpy(thee, "호랑이");
        break;
    case 7:
        strcpy(thee, "토끼");
        break;
    case 8:
        strcpy(thee, "용");
        break;
    case 9:
        strcpy(thee, "뱀");
        break;
    case 10:
        strcpy(thee, "말");
        break;
    case 11:
        strcpy(thee, "양");
        break;

    default:
        printf("오류");
        return -1;
    }
    printf("%s", thee);

    return 0;
}