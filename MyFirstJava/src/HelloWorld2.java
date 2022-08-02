import java.util.Scanner;

public class HelloWorld2 {
	public static void main(String args[]) {

    Scanner s = new Scanner(System.in); //main안에서 수행
    
    //int n;
	//scanf("%d"&n);
	
	
//	  //입력문 종류(숫자) - 한문장에 하나씩 입력받기 int n_int = s.nextInt(); //int 형 입력문 short
//	 sh_short=s.nextShort(); //short형 입력문 float f_float=s.nextFloat(); //float 형
//	 입력문 double d_double=s.nextDouble(); //double형 입력문
//	 
     //공백이 있는 것은 nextLine으로

    System.out.println("이름이 뭔가요");
    String name = s.next();
    
    System.out.println("각오가 뭔가요");
    s.nextLine(); //리와인드 같은 느낌
    String st = s.nextLine();
    
    System.out.println("올해는 몇년도인가요");
    int year = s.nextInt();
    
    System.out.println("Hello world\n");
    System.out.printf("제 이름은 %s입니다.\n",name);
    System.out.println("You are learning Java with "+year);
    System.out.printf("\n각오: ");
    System.out.println(st);
    
	}
}
