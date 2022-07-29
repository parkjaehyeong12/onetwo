#pragma once

//동물병원
//동물의 이름, 동물의 종류, 동물 고유 코드
//뽀삐라는 개가 2마리 이상일 수 있으니
//동물 고유코드로 구분할 것


//내가 만들고 싶은거

struct MyStruct
{
	char name[100];
	char species[100];
	char code[100];
	//만약 int 타입인데 00007넣으면 7혹은 엉뚱한 값이 들어갈 수 있다.

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