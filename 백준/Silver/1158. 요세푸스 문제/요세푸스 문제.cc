#include<iostream>
#include<vector>

using namespace std;
vector<int> vec;
vector<int> res;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    int i = 0;
    while (!vec.empty()) {
        i = (i + k - 1) % vec.size();
        int temp = vec[i];
        res.push_back(temp);
        vec.erase(vec.begin() + i);
    }
    cout << '<';
    for (i = 0; i < res.size() - 1; i++) {
        cout << res[i] << ", ";
    }
    cout << res[res.size() - 1] << ">";
}