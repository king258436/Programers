#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
bool visited[101][101];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int main(){
    int n,x,y;
    queue<pair<int,int>> q;

    cin>>n>>y>>x;

    map[y-1][x-1]=1;
    visited[y-1][x-1]=true;
    q.push({y-1,x-1});
    while(!(q.empty())){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx>=n||nx<0||ny>=n||ny<0||visited[ny][nx]==true){
                continue;
            }
            map[ny][nx]=map[y][x]+1;
            visited[ny][nx]=true;
            q.push({ny,nx});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
}
