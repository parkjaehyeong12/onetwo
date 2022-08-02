import java.util.Scanner;

public class HelloWorld3 {
	public static void main(String args[]) {
		
		Scanner s = new Scanner(System.in);
		
		int num = s.nextInt();
		int score[] = new int [num];
		int sum = 0;
		for(int i = 0;i<num;i++) {
			score[i] = s.nextInt();
			sum+=score[i];
		}
		for(int i =0;i<num;i++) {
			System.out.print(score[i]+ " ");
		}
		System.out.println("합계는 "+sum);

	}
}
