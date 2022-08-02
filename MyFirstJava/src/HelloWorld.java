//package MyFirstJava //출력 안되면

import java.util.Scanner;

public class HelloWorld { 
    public static void main(String args[]) { //c 의 메인
		/*
		 * System.out. printf ("%s", "Hello World!\n"); System.out. print
		 * ("Hello World\n"); //Hello World 출력
		 * 
		 * System.out.printf("%s", "hello world!\n"); System.out.
		 * println("Hello World"); //"Hello World
		 * 
		 * String name = "Park JaeHyeong"; int year = 2022;
		 * 
		 * //System.out. println("Hello World %s", name);
		 * System.out.println("Hello World2 "+name);
		 
		 * 
		 * //System.out printf("You are learning Java with %d", year);
		 * System.out.println("You are learning Java with "+year);
		 * 
		 * // System.out.print("당신의 각오를 말해보세요.\n"); //한글이 안 쓰이네 // //
		 * System.out.println("퇴근하고 저녁 뭐 먹지.\n");
		 */
    	Scanner s = new Scanner(System.in);
    	//int n;
    	//scanf("%d"&n);
    	
    	//입력문 종류(숫자) - 한문장에 하나씩 입력받기
    	int n_int = s.nextInt();         //int 형 입력문
    	short sh_short=s.nextShort();    //short형 입력문
    	float f_float=s.nextFloat();     //float 형 입력문
        double d_double =d.nextDouble(); //double형 입력문
    	
    	//입력문 종류(문자)
        char c_char=s.next().charAt(0);  //char형 입력문 , charAt(0) 은 size 가 1이다는 의미인듯
        String s_st=s.next();            //string형 입력문 (공백 포함 X 입력문)
        String s_str=s.nextLine();       //string형 입력문  (공백포함 0 입력문)
    	
    	
}
}
