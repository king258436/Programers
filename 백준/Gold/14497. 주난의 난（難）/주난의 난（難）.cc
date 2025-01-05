#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n, m;
string map[301];
pair<int, int> junan, criminal;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

pair<int, int> bfs() {
    int ret = 0;
    int flag = 0;
    int visited[301][301] = {
        0,
    };
    queue<pair<int, int>> que;
    que.push({junan.first, junan.second});
    visited[junan.first][junan.second] = 1;
    while (!que.empty()) {
        int curY = que.front().first;
        int curX = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nX = dx[i] + curX;
            int nY = dy[i] + curY;
            if (nX < 0 || nX >= m || nY < 0 || nY >= n || visited[nY][nX] != 0) {
                continue;
            } else if (map[nY][nX] == '1') {
                map[nY][nX] = '0';
                visited[nY][nX] = 1;
                ret++;
            } else if (map[nY][nX] == '0') {
                ret++;
                que.push({nY, nX});
                visited[nY][nX] = 1;
            } else if (map[nY][nX] == '#') {
                flag = 1;
                ret++;
            }
        }
    }
    return {ret, flag};
}
int main() {
    cin >> n >> m;
    cin >> junan.first >> junan.second >> criminal.first >> criminal.second;
    junan.first--;
    junan.second--;
    criminal.first--;
    criminal.second--;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    int result = 0;
    pair<int, int> ret;
    while (1) {
        ret = bfs();
        if (ret.first) {
            result++;
        }
        if (ret.second) {
            cout << result;
            return 0;
        }
        // cout << result << endl;
    }
}