#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string solution(string s) {
    string answer, temp = "";
    int len = s.length();
    vector<int> vec;
    for(int i=0;i<len;i++){
        if(s[i] == ' '){
            vec.push_back(stoi(temp));
            temp="";
        }
        else{
            temp += s[i];
        }
    }
    vec.push_back(stoi(temp));
    sort(vec.begin(),vec.end());
    answer = to_string(vec.front())+" "+to_string(vec.back());
    return answer;
}