//package firsttest;

import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author Asad Bin Saber
 * @date   12 05 2020
 */
public class Main{

    /**
     * @param args the command line arguments
     */
    
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        // TODO code application logic here
        // Integers, doubles are base...
        
        int n, a, b, i;
        
        n = sc.nextInt();
        for(i=1; i<=n; i++){
            a = sc.nextInt();
            b = sc.nextInt();
            System.out.println(a + b + "\n");
        }
        
        //System.out.println("May I know your name?\n");
        
        //String name = sc.nextLine();
        
        //System.out.println("Hello " + name);
    }
}
