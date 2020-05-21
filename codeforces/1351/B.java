import java.util.Scanner;

/**
 *  ...Bismillahir Rahmanir Rahim...
 *    @author Asad Bin Saber
 *     21 May, 2020.
 */
public class Main {
    
    static Scanner sc=new Scanner(System.in);
    
    public static void main(String[] args){
        int n, a, b, c, d;
        
        n = sc.nextInt();
        for(int K=1; K<=n; K++){
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            d = sc.nextInt();
            
            if((a==c && b==d) || (a==d && b==c)){
                if(a*2==b || b*2==a){
                    System.out.println("YES\n");
                }
                else{
                    System.out.println("NO\n");
                }
            }
            else if((a==c && a==b+d) || (a==d && a==b+c) || (b==c && b==a+d) || (b==d && b==a+c)){
                System.out.println("YES\n");
            }
            else{
                System.out.println("NO\n");
            }
        }
    }
}
