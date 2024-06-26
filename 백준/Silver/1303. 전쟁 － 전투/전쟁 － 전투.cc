#include <iostream>
using namespace std;
int n, m;
int map[100][100];
int visited[101][101];
char input[101][101];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int s = 1;
int wSum = 0;
int bSum = 0;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            visited[ny][nx] = 1;
            s++;
            dfs(ny, nx);
        }
    }
}

void reset() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
            map[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == 'W') {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                wSum += s * s;
                s = 1;
            }
        }
    }

    reset();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == 'B') {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                bSum += s * s;
                s = 1;
            }
        }
    }
    cout << wSum << " " << bSum;
    return 0;
}