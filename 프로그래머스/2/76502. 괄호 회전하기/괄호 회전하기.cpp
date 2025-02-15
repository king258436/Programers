#include <string>
#include <vector>
#include <stack>

using namespace std;

bool def(string &s) {
    stack<char> st;
    for(char a : s) {
        if(a == '{' || a == '[' || a == '(') {
            st.push(a);
        }
        else {
            if(st.empty()) return false;  // 닫는 괄호가 먼저 나오는 경우
            
            if((a == '}' && st.top() == '{') ||
               (a == ']' && st.top() == '[') ||
               (a == ')' && st.top() == '(')) {
                st.pop();
            }
            else {
                return false; // 잘못된 괄호 매칭
            }
        }
    }
    return st.empty();  // 스택이 비어 있어야 올바른 괄호열
}

int solution(string s) {
    int answer = 0;

    for(size_t i = 0; i < s.size(); i++) {
        if(def(s)) {
            answer++;
        }
        s.push_back(s[0]);  // 첫 번째 문자를 뒤로 이동
        s.erase(0, 1);          // 앞에서 제거
    }
    return answer;
}
