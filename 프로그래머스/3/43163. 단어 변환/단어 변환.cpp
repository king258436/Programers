#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    // target이 words에 없는 경우
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    queue<pair<string, int>> que;
    bool visited[50] = {false}; // 방문 여부 저장
    que.push({begin, 0}); // 시작 단어와 변환 횟수

    while (!que.empty()) {
        string cur_s = que.front().first;
        int cur_cnt = que.front().second;
        que.pop();

        for (int i = 0; i < words.size(); i++) {
            if (!visited[i]) {
                string next_s = words[i];
                int diff_cnt = 0;

                // 현재 단어와 비교하여 다른 알파벳 개수 계산
                for (int j = 0; j < next_s.size(); j++) {
                    if (cur_s[j] != next_s[j]) diff_cnt++;
                }

                // 한 글자만 다른 경우에만 큐에 추가
                if (diff_cnt == 1) {
                    if (next_s == target) {
                        return cur_cnt + 1; // target에 도달하면 변환 횟수 반환
                    }
                    que.push({next_s, cur_cnt + 1});
                    visited[i] = true; // 방문 처리
                }
            }
        }
    }

    return 0; // target에 도달할 수 없는 경우
}
