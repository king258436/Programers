#include <stdio.h>

typedef struct {
    int x;
    int y;
} Po;

int map[3][3];     // N의 최대 크기 100까지 처리 가능
int visited[3][3]; // 방문 여부를 기록할 배열
int dx[] = {0, 1};     // 오른쪽과 아래로만 이동 가능
int dy[] = {1, 0};

int n; // 게임판의 크기

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
    if (map[cur.y][cur.x] == 0 || visited[cur.y][cur.x]) {
        return 0;
    }

    // 현재 위치 방문 표시
    visited[cur.y][cur.x] = 1;

    int jump = map[cur.y][cur.x];

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
    scanf("%d", &n);   // 동적으로 크기 입력받기
    Po start = {0, 0}; // 출발 지점은 항상 (0, 0)

    // 게임판 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // DFS 탐색 시작
    int result = dfs(start);
    if (result == 0) {
        printf("Hing\n");
    } else {
        printf("HaruHaru\n");
    }

    return 0;
}
