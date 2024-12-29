#include <iostream>
#include <queue>
using namespace std;

typedef struct info {
    int x;
    int y;
    int dist;
} Info;

int map[200][200];
bool visited[200][200];
int dy[] = {-2, -2, 0, 0, 2, 2};
int dx[] = {-1, 1, -2, 2, -1, 1};
int n;
Info start;
Info goal;

int bfs() {
    queue<Info> que;
    que.push(start);
    while (!que.empty()) {
        Info cur = que.front();
        que.pop();
        if (cur.x == goal.x && cur.y == goal.y)
            return cur.dist;
        for (int dir = 0; dir < 6; dir++) {
            Info next;
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];
            next.dist = cur.dist + 1;
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n || visited[next.y][next.x])
                continue;
            que.push(next);
            visited[next.y][next.x] = true;
        }
    }
    return -1;
}
int main() {
    cin >> n;
    cin >> start.y >> start.x >> goal.y >> goal.x;
    start.dist = 0;
    int result = bfs();
    cout << result;
}