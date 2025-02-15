#include <string>
#include <iostream>
using namespace std;

int cnt(string &s,char b){
    int c=0;
    for(char a:s){
        if(a==b||a==b+32){
            c++;
        }
    }
    return c;
}

bool solution(string s)
{
    bool answer = true;

    int p = cnt(s,'P');
    int y = cnt(s,'Y');
    if(p==y){
        return true;
    }
    else{
        return false;
    }

    return answer;
}