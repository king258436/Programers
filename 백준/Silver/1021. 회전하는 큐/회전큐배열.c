#include <stdio.h>

int arr[50];    // 회전하는 큐
int find[50];   // 지민이가 뽑아내야할 원소의 위치
int n, m;       // n: 회전하는 큐의 원소 개수, m: 뽑아낼 원소 개수
int result = 0; // 2, 3번 연산의 최소값 (출력 결과)

// 큐에서 오른쪽으로 몇 번 이동해야 목표 값에 도달하는지 계산하는 함수
int turn_right(int cur_idx, int target_idx, int size) {
    if (cur_idx <= target_idx) {
        return target_idx - cur_idx; // 단순히 오른쪽으로 이동
    }
    else {
        return size - (cur_idx - target_idx); // 원형 큐를 고려한 이동
    }
}

// 큐에서 왼쪽으로 몇 번 이동해야 목표 값에 도달하는지 계산하는 함수
int turn_left(int cur_idx, int target_idx, int size) {
    if (cur_idx >= target_idx) {
        return cur_idx - target_idx; // 단순히 왼쪽으로 이동
    }
    else {
        return size + (cur_idx - target_idx); // 원형 큐를 고려한 이동
    }
}

// 타겟 값이 있는 인덱스를 반환하는 함수
int find_target_idx(int target_value, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target_value) {
            return i;
        }
    }
}

// 뽑아낸 후 큐를 재정렬하는 함수
void remove_element(int idx, int *size) {
    (*size)--; // 큐 크기 감소
    for (int i = idx; i < (*size); i++) {
        arr[i] = arr[i + 1]; // 하나씩 당겨서 재정렬
    }
}

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
        int target = find[i];                        // 이번에 뽑아야 할 값
        int target_idx = find_target_idx(target, n); // 타겟 인덱스 찾기

        // 왼쪽, 오른쪽 이동 횟수 계산
        int left_moves = turn_left(cur_idx, target_idx, n);
        int right_moves = turn_right(cur_idx, target_idx, n);

        // 최소 이동 횟수 선택
        if (left_moves < right_moves) {
            result += left_moves;
            cur_idx = target_idx;
        }
        else {
            result += right_moves;
            cur_idx = target_idx;
        }

        // 원소 제거 및 큐 재정렬
        remove_element(cur_idx, &n);

        // 원소를 제거한 후 현재 인덱스가 큐의 범위를 넘으면 다시 첫 인덱스로 설정
        if (cur_idx == n) {
            cur_idx = 0;
        }
    }

    // 결과 출력
    printf("%d\n", result);
}
