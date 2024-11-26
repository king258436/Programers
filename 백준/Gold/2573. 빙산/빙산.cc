#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct info {
    int y, x;
} Info;

int map[300][300];
bool visited[300][300];
int dy[] = {0, 1, -1, 0};
int dx[] = {1, 0, 0, -1};
int n, m;

void change_map(int cur[][300], int after[][300]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            after[i][j] = cur[i][j];
        }
    }
}

void bfs(int y, int x) {
    queue<Info> que;
    que.push({y, x});
    visited[y][x] = true;

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && map[ny][nx] > 0) {
                visited[ny][nx] = true;
                que.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;

    while (1) {
        int new_map[300][300] = {0};
        int island = 0;
        memset(visited, false, sizeof(visited));

        // 빙산 높이 감소 계산
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0) {
                    int cnt = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] <= 0) {
                            cnt++;
                        }
                    }
                    new_map[i][j] = max(0, map[i][j] - cnt);
                }
            }
        }

        // 덩어리 개수 계산
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                    island++;
                }
            }
        }

        change_map(new_map, map);

        if (island == 0) {
            cout << 0;
            break;
        } else if (island >= 2) {
            cout << year ;
            break;
        }

        year++;
    }

    return 0;
}
