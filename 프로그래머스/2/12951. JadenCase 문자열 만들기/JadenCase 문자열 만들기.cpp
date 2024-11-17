#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    bool f_flag = true; // 단어의 첫 글자인지 여부
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            // 공백일 경우 다음 문자를 단어의 시작으로 설정
            f_flag = true;
        } else if (f_flag) {
            // 단어의 첫 글자 처리
            if (isalpha(s[i])) {
                s[i] = toupper(s[i]); // 알파벳인 경우 대문자로
            }
            f_flag = false; // 단어 시작 후 첫 글자 처리 완료
        } else {
            // 단어의 첫 글자가 아닌 경우 소문자로 변환
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
    }

    return s;
}
