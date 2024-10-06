#include <stdio.h>

typedef struct {
    int x;
    int y;
} Po;
int n;
int map[3][3];
int dx[] = {0, 1};
int dy[] = {1, 0};

int dfs(Po cur) {
    // 현재 좌표가 배열 범위를 벗어나지 않는지 확인
    if (cur.x < 0 || cur.x >= n || cur.y < 0 || cur.y >= n) {
        return 0;
    }

    // 목적지에 도착한 경우
    if (map[cur.y][cur.x] == -1) {
        return 1;
    }

    // 이미 방문했거나 값이 0인 경우
    if (map[cur.y][cur.x] == 0) {
        return 0;
    }

    // 현재 위치 방문 표시
    int jump = map[cur.y][cur.x];
    map[cur.y][cur.x] = 0;

    // 두 방향으로 재귀적으로 탐색
    for (int dir = 0; dir < 2; dir++) {
        int ny = cur.y + dy[dir] * jump;
        int nx = cur.x + dx[dir] * jump;
        Po next = {nx, ny};

        if (dfs(next)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    scanf("%d",&n);
    Po start = {0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int result = dfs(start);
    if (result == 0) {
        printf("Hing");
    } else {
        printf("HaruHaru");
    }

    return 0;
}
