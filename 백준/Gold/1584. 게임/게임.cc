#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;
int map[501][501];
int score[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs() {
    queue<pair<int, int>> que;
    que.push({0, 0});
    score[0][0] = 0;
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (nx < 0 || ny < 0 || nx >= 501 || ny >= 501 || map[ny][nx] == 2) {
                continue;
            }
            if (map[ny][nx] == 1 && score[ny][nx] > score[cur.first][cur.second] + 1) {
                que.push({ny, nx});
                score[ny][nx] = score[cur.first][cur.second] + 1;
            } else if (map[ny][nx] == 0 && score[ny][nx] > score[cur.first][cur.second]) {
                que.push({ny, nx});
                score[ny][nx] = score[cur.first][cur.second];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            score[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int minX = min(x1, x2);
        int minY = min(y1, y2);
        int maxX = max(x1, x2);
        int maxY = max(y1, y2);

        for (int i = minY; i <= maxY; i++) {
            for (int j = minX; j <= maxX; j++) {
                map[i][j] = 1;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int minX = min(x1, x2);
        int minY = min(y1, y2);
        int maxX = max(x1, x2);
        int maxY = max(y1, y2);

        for (int i = minY; i <= maxY; i++) {
            for (int j = minX; j <= maxX; j++) {
                map[i][j] = 2;
            }
        }
    }

    bfs();

    if (score[500][500] == INF) {
        cout << -1;
    } else {
        cout << score[500][500];
    }

    return 0;
}
