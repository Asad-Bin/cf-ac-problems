import java.util.Scanner;

public class Hello {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int i = 1, t = sc.nextInt();
		
		while(i<=t){
			t--;
			
			int a = sc.nextInt();
			
			int b = sc.nextInt();
			
			System.out.println(a+b);
		}
	}
}