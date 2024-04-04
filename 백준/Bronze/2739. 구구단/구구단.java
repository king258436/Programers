import java.util.Scanner;
import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n=sc.nextInt();
        for(int i=1;i<=9;i++){
            System.out.println(n+" * "+ i +" = "+i*n);
        }

    }
}