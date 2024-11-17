#include<string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    string stack;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            stack+="(";
        }
        else{
            if(stack.back()!='('){
                return false;
            }
            else{
                stack.pop_back();
            }
        }
    }
    if(stack!=""){
        return false;
    }

    return answer;
}