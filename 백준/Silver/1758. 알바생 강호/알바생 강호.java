import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n=sc.nextInt();
        Long[] arr = new Long[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextLong();
        }
        Arrays.sort(arr, Collections.reverseOrder());
        long result=0;
        for(int i=0;i<n;i++){
            if(arr[i]-i>0) result+=arr[i]-i;
        }
        System.out.println(result);

    }
}