#include<iostream>
#include<queue>

using namespace std;
int arr[101][101];
bool visited[101];
queue<int> q;
int n;
int cnt;

void bfs(int v) {
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (arr[v][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main() {

    int m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    bfs(1);
    cout << cnt;

}