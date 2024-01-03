import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[] = new int[8];
        for(int i=0;i<8;i++){
            arr[i]=in.nextInt();
        }
        int mode = 0; // 0 == mixed, 1 == ascending, -1 == descending
        if(arr[0]==1){
            mode =1;
        }
        else if(arr[0]==8){
            mode = -1;
        }
        else {
            mode =0;
        }
        if(mode==1) {
            for (int i = 1; i < 8; i++) {
                if (arr[i]!=arr[i-1]+1){
                    mode=0;
                    break;
                }
            }
        }
        else if(mode==-1){
            for (int i = 1; i < 8; i++) {
                if (arr[i]!=arr[i-1]-1){
                    mode=0;
                    break;
                }
            }
        }
        if(mode==0){
            System.out.println("mixed");
        }
        else if(mode==1){
            System.out.println("ascending");
        }
        else{
            System.out.println("descending");
        }
    }
}