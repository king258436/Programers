import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        for(int i=0;i<n;i++){
            String str = in.next();
            int plus=1;
            int result=0;
            for(int j=0;j<str.length();j++){
                if(str.charAt(j)=='X'){
                    plus=1;
                }
                else{
                    result+=plus;
                    plus++;
                }
            }
            System.out.println(result);
        }

    }
}