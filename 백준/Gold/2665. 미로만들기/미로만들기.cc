#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INF 100000000
using namespace std;
string map[50];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int check[50][50];
int n;

void bfs() {
    queue<pair<int, int>> que;
    que.push({0, 0});
    check[0][0] = 1;
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nextX = cur.second + dx[dir];
            int nextY = cur.first + dy[dir];
            if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
                if (map[nextY][nextX] == '0' && check[nextY][nextX] > check[cur.first][cur.second] + 1) {
                    que.push({nextY, nextX});
                    check[nextY][nextX] = check[cur.first][cur.second] + 1;
                } else if (map[nextY][nextX] == '1' && check[nextY][nextX] > check[cur.first][cur.second]) {
                    que.push({nextY, nextX});
                    check[nextY][nextX] = check[cur.first][cur.second];
                }
            }
        }
    }
}
int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = INF;
        }
    }
    bfs();
    cout << check[n - 1][n - 1] - 1;
}