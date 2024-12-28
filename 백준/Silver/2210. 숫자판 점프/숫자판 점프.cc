#include<iostream>
#include<set>
#include<string>
using namespace std;
int arr[5][5];
set<string> s;
int dx[] ={0,0,-1,1};
int dy[] ={1,-1,0,0};
void dfs(int depth, string str,int y,int x){
    if(depth>6){
        s.insert(str);
        return ;
    }
    else {
        str+='0'+arr[y][x];
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx<0||nx>=5||ny<0||ny>=5) continue;
            dfs(depth+1,str,ny,nx);
        }
    }
    return ;
}
int main(){
    string str;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(1,str,i,j);
        }
    }
    cout<<s.size();
}