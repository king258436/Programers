#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    int s_len = s.length();
    bool f_flag = true; // 단어의 첫 글자인지 여부

    for (int i = 0; i < s_len; i++) {
        if (s[i] == ' ') {
            // 공백을 만나면 단어의 시작으로 설정
            f_flag = true;
        } else if (f_flag) {
            // 단어의 첫 글자 처리
            if (isalpha(s[i])) {
                s[i] = toupper(s[i]);
            }
            f_flag = false; // 단어 시작 완료
        } else {
            // 단어 첫 글자가 아닌 경우 소문자로
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
    }

    return s;
}
