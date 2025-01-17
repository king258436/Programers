#include <string>
#include <vector>

using namespace std;
bool visited[200];
void dfs(int cur,vector<vector<int>> &computers,int n){
    visited[cur]=true;
    for(int i=0;i<n;i++){
        if(!visited[i]&&computers[cur][i]){
            dfs(i,computers,n);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,computers,n);
            answer++;
        }
    }
    return answer;
}