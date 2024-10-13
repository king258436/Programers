#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;
int main() {
    int n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int col = 0, row = 0;
    for (int i = 0; i < n; i++) {
        bool r_flag = false;
        bool c_flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (vec[i][j] == vec[i][j + 1] && vec[i][j] == '.') {
                if (!r_flag) {
                    row++;
                    r_flag = true;
                }
            } else {
                r_flag = false;
            }
            if (vec[j][i] == vec[j + 1][i] && vec[j][i] == '.') {
                if (!c_flag) {
                    col++;
                    c_flag = true;
                }
            } else {
                c_flag = false;
            }
        }
    }
    cout << row << ' ' << col;
}