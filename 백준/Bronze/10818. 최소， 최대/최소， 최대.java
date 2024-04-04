import java.util.Scanner;
import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n=sc.nextInt();
        Integer[] arr = new Integer[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int min_val= (int) 2e9;
        int max_val= (int) -2e9;

        for(int i=0;i<n;i++){
            min_val=min(arr[i],min_val);
            max_val=max(arr[i],max_val);
        }
        System.out.println(min_val+" "+max_val);

    }
}