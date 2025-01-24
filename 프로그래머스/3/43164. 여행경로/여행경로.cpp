#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(string cur,bool (&check)[10001],vector<vector<string>> const &tickets,vector<string>&answer, int cnt){
    int size = tickets.size();
    answer.push_back(cur);
    if(cnt==size){
        return true;
    }
    for(int i=0;i<size;i++){
        if(tickets[i][0]==cur&&!check[i]){
            check[i]=true;
            bool re = dfs(tickets[i][1],check,tickets,answer,cnt+1);
            if(re==true) return true;
            check[i]=false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(),tickets.end());
    bool check[10001]={0,};
    dfs("ICN",check,tickets,answer,0);
    return answer;
}