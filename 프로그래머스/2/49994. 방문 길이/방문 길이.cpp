#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    string str = dirs;
    pair<int,int> cur={0,0}, next;
    set<pair<pair<int,int>,pair<int,int>>> s;
    for(auto a : dirs){
        if(a=='U'){
            next = {cur.first+1,cur.second};
        }
        else if(a=='D'){
            next = {cur.first-1,cur.second};
        }
        else if(a=='R'){
            next = {cur.first,cur.second+1};
        }
        else if(a=='L'){
            next = {cur.first,cur.second-1};
        }
        if(next.first>5||next.second>5||next.first<-5||next.second<-5)
            continue;
        
        auto ret = s.insert({cur,next});
        auto ret2 = s.insert({next,cur});
        cur=next;
        if(ret.second||ret2.second)answer++;
    }
    return answer;
}