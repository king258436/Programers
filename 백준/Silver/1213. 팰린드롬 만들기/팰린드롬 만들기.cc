#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, cpy;
    int cnt[26] = {0};
    
    // 문자열 입력
    cin >> str;
    int s = str.length();
    
    // 각 알파벳 개수 세기
    for (int i = 0; i < s; i++) {
        cnt[str[i] - 'A']++;
    }

    // 홀수 개수인 알파벳의 개수를 세기
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) odd++;
    }

    // 문자열의 길이가 짝수면 홀수 개의 알파벳이 있으면 안 되고,
    // 문자열의 길이가 홀수면 홀수 개의 알파벳이 1개 이상이면 안됨.
    if (s % 2 == 0 && odd != 0 || s % 2 == 1 && odd > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    // 결과 문자열 크기 설정
    cpy.resize(s);

    int idx = 0;
    char mid = 0; // 홀수 개수인 알파벳이 있을 경우 중간에 넣을 문자

    // 대칭으로 알파벳을 넣기
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            mid = i + 'A'; // 홀수 개수인 알파벳은 중간에 넣음
            cnt[i]--;
        }
        // 대칭으로 알파벳을 앞뒤에 채우기
        for (int j = 0; j < cnt[i] / 2; j++) {
            cpy[idx] = i + 'A';
            cpy[s - idx - 1] = i + 'A';
            idx++;
        }
    }

    // 만약 홀수 개수인 알파벳이 있으면 중간에 넣기
    if (mid != 0) {
        cpy[s / 2] = mid;
    }

    // 결과 출력
    cout << cpy;
    return 0;
}
