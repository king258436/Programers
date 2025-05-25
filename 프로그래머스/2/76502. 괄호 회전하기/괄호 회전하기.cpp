#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

map<char,char> m= {{'}','{'},{']','['},{')','('}};
bool isValid(string &s, int start){
    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(m.find(s[(start+i)%s.length()])==m.end()){
            stk.push(s[(start+i)%s.length()]);
        }
        else{
            if(!stk.empty()&&stk.top()==m[s[(start+i)%s.length()]]){
                stk.pop();
            }
            else return false;
        }
    }
    if(stk.empty()){
        return true;
    }
    else return false;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.length();i++){
        if(isValid(s,i)){
            answer++;
        }
    }
    return answer;
}