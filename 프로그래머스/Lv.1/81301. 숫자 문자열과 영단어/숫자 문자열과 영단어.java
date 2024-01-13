class Solution {
    public int solution(String s) {
        String[] arr = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        int len = arr.length;
        for(int i=0;i<len;i++){
            if(s.contains(arr[i])){
                s=s.replace(arr[i],Integer.toString(i));
            }
        }
        return Integer.parseInt(s);
    }

}