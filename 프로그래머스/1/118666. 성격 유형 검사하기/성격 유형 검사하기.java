class Solution {

    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int[] intArr = new int[200];
        int len = survey.length;
        for (int i = 0; i < len; i++) {
            if (choices[i] <= 3) {
                intArr[survey[i].charAt(0)] += 4 - choices[i];
            } else if (choices[i] > 4) {
                intArr[survey[i].charAt(1)] += choices[i] - 4;
            }
        }
        if (intArr['R'] >= intArr['T']) {
            answer += "R";
        } else {
            answer += "T";
        }
        if (intArr['C'] >= intArr['F']) {
            answer += "C";
        } else {
            answer += "F";
        }
        if (intArr['J'] >= intArr['M']) {
            answer += "J";
        } else {
            answer += "M";
        }
        if (intArr['A'] >= intArr['N']) {
            answer += "A";
        } else {
            answer += "N";
        }
        return answer;

    }
}