#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    int size = words.size();
    for(int i=0;i<size;i++){
        if(i>0&&words[i-1][words[i-1].length()-1]!=words[i][0]){
            answer.push_back((i+1)%n==0?n:(i+1)%n);
            answer.push_back(i/n+1);
            return answer;
        }
        if(s.find(words[i])==s.end()){
            s.insert(words[i]);
        }
        else{
            answer.push_back((i+1)%n==0?n:(i+1)%n);
            answer.push_back(i/n+1);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}