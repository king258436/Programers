#include <stdio.h>

int arr[50];   // 회전하는 큐
int find[50];  // 지민이가 뽑아내야할 원소의 위치
int n, m;      // n: 회전하는 큐의 원소 개수, m: 뽑아낼 원소 개수
int result = 0; // 2, 3번 연산의 최소값 (출력 결과)

int main() {
    int cur_idx = 0; // 현재 큐의 첫 번째 인덱스
    scanf("%d %d", &n, &m);

    // 뽑아내야 할 값 입력 받기
    for (int i = 0; i < m; i++) {
        scanf("%d", &find[i]);
    }

    // 큐 초기화 (1 ~ n까지)
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // 각 뽑아야 할 원소에 대해 연산 수행
    for (int i = 0; i < m; i++) {
        int target = find[i]; // 이번에 뽑아야 할 값
        int left_moves = 0, right_moves = 0;

        // 현재 큐에서 target이 어디 있는지 찾기
        int target_idx = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == target) {
                target_idx = j;
                break;
            }
        }

        // 왼쪽으로 이동하는 경우 (현재 인덱스에서 목표 인덱스까지의 거리)
        if (cur_idx <= target_idx) {
            right_moves = target_idx - cur_idx;
            left_moves = cur_idx + (n - target_idx);
        } else {
            right_moves = (n - cur_idx) + target_idx;
            left_moves = cur_idx - target_idx;
        }

        // 최소 이동 횟수 선택
        if (left_moves < right_moves) {
            result += left_moves;
            cur_idx = target_idx;
        } else {
            result += right_moves;
            cur_idx = target_idx;
        }

        // 원소 제거 (뽑아낸 원소는 0으로 설정)
        arr[cur_idx] = 0;

        // 남은 원소 재정렬
        for (int j = cur_idx; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        n--; // 큐 크기 감소
        if (cur_idx == n) {
            cur_idx = 0; // 인덱스가 범위를 넘으면 0으로 돌림
        }
    }

    // 결과 출력
    printf("%d\n", result);
}
