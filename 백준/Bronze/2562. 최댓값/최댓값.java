import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int [] arr = new int[9];
        int [] arr_s= new int[9];

        for(int i=0;i<9;i++){
            arr[i]=in.nextInt();
            arr_s[i]=arr[i];
        }
        Arrays.sort(arr_s);
        int max = arr_s[8];
        int order=0;
        for(int i=0;i<9;i++){
            if(max==arr[i]){
                order=i+1;
                break;
            }
        }
        System.out.println(max+"\n"+order);

    }
}