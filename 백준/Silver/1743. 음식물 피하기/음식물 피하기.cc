#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> q;
int n, m, k;
vector<vector<int>> vec, visited;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int biggest = 0;

int bfs(int y, int x) {
    int cnt = 0;
    q.push({y, x});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] || !vec[ny][nx]) {
                continue;
            }
            q.push({ny, nx});
            visited[ny][nx] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m >> k;
    vec.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        vec[i].resize(m);
        visited[i].resize(m);
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        vec[y - 1][x - 1] = 1;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && vec[i][j]) {
                int cnt = bfs(i, j);
                result = max(cnt, result);
            }
        }
    }
    cout << result;
}