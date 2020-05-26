import java.util.Scanner;

/**
 *  ...Bismillahir Rahmanir Rahim...
 *    @author Asad Bin Saber
 *     21 May, 2020.
 */
public class Main {
    
    static Scanner sc=new Scanner(System.in);
    
    public static void main(String[] args){
        int t, n, k;
        
        //t = sc.nextInt();
        //while(t--!=0){
            n = sc.nextInt();
            k = sc.nextInt();
            int[] ara = new int[201];
            
            for(int K=0; K<2*n+1; K++) ara[K] = sc.nextInt();
            
            for(int K=1; K<2*n+1; K+=2){
                if(ara[K]-1>ara[K-1] && ara[K]-1>ara[K+1]){
                    ara[K]--;
                    k--;
                }
                
                if(k==0) break;
            }
            
            for(int K=0; K<2*n+1; K++){
                System.out.print(ara[K]+" ");
            }
            System.out.println("\n");
        //}
    }
}