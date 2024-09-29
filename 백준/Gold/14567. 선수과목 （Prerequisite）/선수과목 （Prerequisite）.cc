#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;                    // 과목 수 N, 선수 조건 수 M
vector< vector< int > > adj; // 인접 리스트 (b -> a: b는 a의 선수 과목)
vector< int > semester;      // 각 과목을 이수할 최소 학기 수
vector< int > visited; // 방문 여부 체크 (0: 미방문, 1: 방문 중, 2: 방문 완료)
bool hasCycle = false; // 사이클 존재 여부

// 과목을 DFS로 탐색하여 최소 학기 계산
int dfs(int course) {
  if (visited[course] == 1) { // 현재 경로에 이미 방문한
    hasCycle = true;
    return 0;
  }
  if (visited[course] == 2) { // 이미 방문 완료한 노드면 저장된 학기 수 반환
    return semester[course];
  }

  visited[course] = 1; // 현재 노드를 방문 중으로 표시
  int maxSemester = 1; // 최소 1학기에는 이수할 수 있음

  for (int pre : adj[course]) { // 현재 과목의 모든 선수 과목에 대해
    int sem = dfs(pre);         // 선수 과목의 학기 수 계산
    maxSemester = max(maxSemester, sem + 1); // 최대 학기 수 업데이트
  }

  semester[course] = maxSemester; // 해당 과목의 최소 학기 수 저장
  visited[course] = 2;            // 방문 완료로 표시
  return semester[course];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  adj.assign(N + 1, vector< int >()); // 1번 과목부터 N번 과목까지 사용
  semester.assign(N + 1, 0);          // 학기 수 초기화
  visited.assign(N + 1, 0);           // 방문 여부 초기화

  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    adj[B].push_back(A); // B는 A의 선수 과목
  }

  // 모든 과목에 대해 DFS 수행
  for (int i = 1; i <= N; i++) {
    if (visited[i] == 0) {
      dfs(i);
      if (hasCycle)
        break; // 사이클이 발견되면 더 이상 진행하지 않음
    }
  }

  if (hasCycle) {
    cout << "INVALID HYPOTHESIS\n";
  } else {
    for (int i = 1; i <= N; i++) {
      cout << semester[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}
