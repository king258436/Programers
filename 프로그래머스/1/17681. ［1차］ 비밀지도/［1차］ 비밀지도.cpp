#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        string a = "", b = "", result = "";

        // arr1[i]와 arr2[i]를 2진수로 변환
        int tmp = arr1[i];
        while (tmp > 0) {
            a = (tmp % 2 ? "1" : "0") + a;  // 앞에 추가
            tmp /= 2;
        }
        tmp = arr2[i];
        while (tmp > 0) {
            b = (tmp % 2 ? "1" : "0") + b;  // 앞에 추가
            tmp /= 2;
        }

        // 길이 맞추기 (n자리로 고정)
        while (a.length() < n) a = "0" + a;
        while (b.length() < n) b = "0" + b;

        // 두 2진수의 OR 연산 결과로 "#" 또는 " " 결정
        for (int j = 0; j < n; j++) {
            if (a[j] == '1' || b[j] == '1') {
                result += "#";
            } else {
                result += " ";
            }
        }

        answer.push_back(result);
    }

    return answer;
}
