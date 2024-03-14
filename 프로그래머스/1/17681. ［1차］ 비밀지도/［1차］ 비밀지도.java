class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i=0;i<n;i++){
            String a1=man_func(arr1[i],n);
            String a2=man_func(arr2[i],n);
            String line="";
            for(int j=0;j<n;j++){
                if(a1.charAt(j)=='0'&&a2.charAt(j)=='0'){
                    line+=" ";
                }
                else{
                    line+="#";
                }
            }
            answer[i]=line;
        }
        return answer;
    }
    public String man_func(int num,int n){
        int len=Integer.toBinaryString(num).length();
        String a = Integer.toBinaryString(num);
        for(int i=0;i<n-len;i++){
            a="0"+a;
        }
        return a;
    }
}