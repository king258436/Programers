import java.util.HashMap;

class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        int len=numbers.length;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0;i<len;i++){
            map.put(numbers[i],numbers[i]);
        }
        for(int i=0;i<10;i++){
            if(!map.containsKey(i)){
                answer=answer+i;
            }
        }
        return answer;
    }
}