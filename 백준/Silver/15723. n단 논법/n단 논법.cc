#include <algorithm>
#include <iostream>
#include <string>
#define INF 1e9

using namespace std;

int n, m;
int adj[200][200];

int main() {
    cin >> n;

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (i == j)
                adj[i][j] = 1; // 자기 자신으로의 연결은 항상 참
            else
                adj[i][j] = 0; // 기본적으로 연결되지 않음
        }
    }

    for (int i = 0; i < n; i++) {
        char a, b;
        string s;
        cin >> a >> s >> b;
        adj[a][b] = 1; // 연결 설정
    }

    // 플로이드워셜
    for (int k = 'a'; k <= 'z'; k++) {
        for (int i = 'a'; i <= 'z'; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (adj[i][k] == 1 && adj[k][j] == 1) {
                    adj[i][j] = 1; // 연결 여부 갱신
                }
            }
        }
    }

    // 결론 입력 및 확인
    cin >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        string s;
        cin >> a >> s >> b;
        if (adj[a][b] == 1) {
            cout << 'T' << endl; // 참
        } else {
            cout << 'F' << endl; // 거짓
        }
    }

    return 0;
}
