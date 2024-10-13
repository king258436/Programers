#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> vec;

int main(){
    int n;
    cin >> n;
    vec.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    
    int col = 0, row = 0;
    
    for(int i = 0; i < n; i++){
        bool r_flag = false;  // 매 행마다 다시 초기화
        bool c_flag = false;  // 매 열마다 다시 초기화
        
        for(int j = 0; j < n - 1; j++){
            // 가로 연속 '.' 체크
            if (vec[i][j] == '.' && vec[i][j+1] == '.') {
                if (!r_flag) {
                    row++;
                    r_flag = true;
                }
            } else {
                r_flag = false;  // 연속되지 않으면 플래그 초기화
            }

            // 세로 연속 '.' 체크
            if (vec[j][i] == '.' && vec[j+1][i] == '.') {
                if (!c_flag) {
                    col++;
                    c_flag = true;
                }
            } else {
                c_flag = false;  // 연속되지 않으면 플래그 초기화
            }
        }
    }
    
    cout << row << ' ' << col;
}
