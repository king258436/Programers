#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, cpy;
    int cnt[26] = {
        0,
    };
    cin >> str;
    int s = str.length();
    for (int i = 0; i < s; i++) {
        cnt[str[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1)
            odd++;
    }
    if (s % 2 == 0 && odd != 0 || s % 2 == 1 && odd > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    cpy.resize(s);
    if (s % 2 == 0) {
        int idx = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    cpy[idx] = i + 'A';
                    cpy[s - idx - 1] = i + 'A';
                    idx++;
                }
            }
        }
    } else {
        int idx = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                if (cnt[i] % 2 == 1) {
                    cpy[s / 2] = i + 'A';
                    cnt[i]--;
                    for (int j = 0; j < cnt[i] / 2; j++) {
                        cpy[idx] = i + 'A';
                        cpy[s - idx - 1] = i + 'A';
                        idx++;
                    }
                    continue;
                }
            }
            for (int j = 0; j < cnt[i] / 2; j++) {
                cpy[idx] = i + 'A';
                cpy[s - idx - 1] = i + 'A';
                idx++;
            }
        }
    }
    cout << cpy;
}
