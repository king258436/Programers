import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);// 일단 입력받을라고하면 이렇게 객체를 생성해 줘야한다.

        int N = in.nextInt();// n 입력받음
        int[] arr= new int[N];// N 만큼의 크기를 가진 int형 배열 arr 생성

        for(int i=0;i<N;i++){
            arr[i] = in.nextInt();
        }

        in.close();
        Arrays.sort(arr);
        System.out.println(arr[0]+" "+arr[N-1]);
    }
}