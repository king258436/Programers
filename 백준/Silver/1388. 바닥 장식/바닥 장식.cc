#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
char map[51][51];
bool visited[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs1(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[y][x] = true;
    while (!que.empty()) {
        pair<int, int> cur;
        cur.first = que.front().first;
        cur.second = que.front().second;
        que.pop();
        for (int dir = 0; dir < 2; dir++) {
            pair<int, int> next;
            next.first = cur.first + dx[dir];
            next.second = cur.second + dy[dir];
            if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n ||
                visited[next.second][next.first] || map[next.second][next.first] != '|') {
                continue;
            }
            visited[next.second][next.first] = true;
            que.push(next);
        }
    }
}
void bfs2(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[y][x] = true;
    while (!que.empty()) {
        pair<int, int> cur;
        cur.first = que.front().first;
        cur.second = que.front().second;
        que.pop();
        for (int dir = 2; dir < 4; dir++) {
            pair<int, int> next;
            next.first = cur.first + dx[dir];
            next.second = cur.second + dy[dir];
            if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n ||
                visited[next.second][next.first] || map[next.second][next.first] != '-') {
                continue;
            }
            visited[next.second][next.first] = true;
            que.push(next);
        }
    }
}

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (map[i][j] == '-') {
                    bfs2(j, i);
                    cnt++;
                } else {
                    bfs1(j, i);
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}