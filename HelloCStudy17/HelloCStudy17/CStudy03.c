#include<stdio.h>
#include"Mystructs.h" //구조체 접근
void printAnimal(Animal ani) //새로운 자료형이지, 문자 숫자 다 짬뽕
{
	printf("동물명 : %s\n",ani.name);
	printf("동물종 : %s\n",ani.species);
	printf("동물코드 : %s\n",ani.code);

}
Food FoodTruck() // 구조체를 반환한다는 것
{
	Food f; //구조체 Food를 반환하는 함수 안에서 구조체Food 형태를 띠는
	//변수 f를 선언한다. 헤더파일 안에 있으므로 속성들도 이용가능하지
	printf("음식의 가격은? ");
	scanf_s("%d", &f.price);
	printf("음식명? ");
	rewind(stdin);
	gets(f.name);
	return f;
}


int main()
{
	Animal a1 = { "햄토리", "뉴트리아", "0001" };
	Animal a2 = { .name = "햄토리",.species = "개", "0002" };
	Animal a3;
	strcpy(a3.name, "피카츄");
	strcpy(a3.species, "쥐");
	strcpy(a3.code, "025");
	Animal a4;
	gets(a4.name);
	gets(a4.species);
	gets(a4.code);

	printf("%s %s %s\n", a1.name, a1.species, a1.code);
	printf("%s %s %s\n", a2.name, a2.species, a2.code);
	printf("%s %s %s\n", a3.name, a3.species, a3.code);
	printf("%s %s %s\n", a4.name, a4.species, a4.code);

	Food f1 = { 5500,"학식" };
	Food f2 = { .price = 700000,.name = "일식" };
	Food f3;
	f3.price = 500000;
	strcpy(f3.name, "한식");
	Food f4;
	scanf_s("%d", &f4.price);
	rewind(stdin);
	gets(f4.name);

	printf("%s %d\n", f1.name, f1.price);
	printf("%s %d\n", f2.name, f2.price);
	printf("%s %d\n", f3.name, f3.price);
	printf("%s %d\n", f4.name, f4.price);

	printAnimal(a1);
	printAnimal(a2);
	printAnimal(a3);

	printf("음식 차 갑니다 ");
	Food myfood = FoodTruck();
	printf("%s %d\n", myfood.name, myfood.price);

	return 0;
}