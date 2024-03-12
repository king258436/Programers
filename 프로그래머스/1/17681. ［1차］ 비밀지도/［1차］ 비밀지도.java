class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i=0;i<n;i++){
            String b1=tobinary(n,arr1[i]);
            String b2=tobinary(n,arr2[i]);
            String line ="";
            for(int j=0;j<n;j++){
                if(b1.charAt(j)=='1'||b2.charAt(j)=='1'){
                    line = line+"#";
                }
                else{
                    line = line+" ";
                }
            }
            answer[i]=line;
        }
        return answer;
    }
    public String tobinary(int n, int num){
        String bin = Integer.toBinaryString(num);
        int strlen = bin.length();
        for(int i=0;i<n-strlen;i++){
            bin = "0"+bin;
        }
        return bin;
    }
}