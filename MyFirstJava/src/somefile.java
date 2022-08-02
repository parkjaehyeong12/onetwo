
import java.util.Scanner;

public class somefile {
        public static void main(String args[]) {
        	
        	Scanner s = new Scanner(System.in);
       
        	String str =s.next();
       
       int alphabet[] = new int[26];
       
       
       for(int i = 0;i<str.length();i++) {
    	   int index = str.charAt(i) - (int)'a';
    	   alphabet[index]++;
       }
       
       for(int i =0;i<alphabet.length;i++) {
    	if(alphabet[i]!=0)
    		{
    		System.out.println(""+(char)(i+97)+""+"는"+(alphabet[i]));
    		}
    	}
     }
}
