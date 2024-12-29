#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string map[3000];
int visited[3000][3000];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;

int bfs(int y, int x) {
    queue<pair<int, int>> que;
    que.push({y, x});
    visited[y][x] = 1;
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        // cout << cur.first << ',' << cur.second << endl;
        if (map[cur.first][cur.second] == '3' || map[cur.first][cur.second] == '4' ||
            map[cur.first][cur.second] == '5') {
            return visited[cur.first][cur.second];
        }
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || map[ny][nx] == '1')
                continue;
            que.push({ny, nx});
            visited[ny][nx] = visited[cur.first][cur.second] + 1;
        }
    }
    return -1;
}

int main() {
    pair<int, int> ddak;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '2') {
                ddak.first = i;
                ddak.second = j;
            }
        }
    }
    // cout << ddak.first << ddak.second;
    int result = bfs(ddak.first, ddak.second);
    if (result != -1) {
        cout << "TAK" << endl << result - 1;
    } else {
        cout << "NIE";
    }
}