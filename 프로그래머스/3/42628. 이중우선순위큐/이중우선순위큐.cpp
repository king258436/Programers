#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
int mid = 0, vmax = INT_MIN, vmin = INT_MAX;

void rebalance() {
    stack<int> st;
    vmax = INT_MIN;
    vmin = INT_MAX;
    mid = INT_MAX;

    while (!minq.empty()) {
        maxq.push(minq.top()); minq.pop();
    }
    while (!maxq.empty()) {
        st.push(maxq.top()); maxq.pop();
    }
    int n = st.size();
    for (int i = 0; i < n / 2; ++i) {
        mid = st.top();
        vmax = max(vmax, st.top());
        vmin = min(vmin, st.top());
        minq.push(st.top()); st.pop();
    }
    while (!st.empty()) {
        mid = min(mid, st.top());
        vmax = max(vmax, st.top());
        vmin = min(vmin, st.top());
        maxq.push(st.top()); st.pop();
    }
}

vector<int> solution(vector<string> operations) {
    for (auto& s : operations) {
        if (s[0] == 'D') {
            if (maxq.empty() && minq.empty()) continue;
            if (maxq.empty() && minq.size() == 1) {
                minq.pop();
                continue;
            }
            if (minq.empty() && maxq.size() == 1) {
                maxq.pop();
                continue;
            }
            if (s[2] == '1') {
                if (maxq.empty()) rebalance();
                maxq.pop();
            } else {
                if (minq.empty()) rebalance();
                minq.pop();
            }
        } else {
            int n = stoi(s.substr(2));

            if (!minq.empty() && n <= minq.top() || n <= mid)
                minq.push(n);
            else
                maxq.push(n);
        }
    }
    rebalance();
    return {vmax == INT_MIN ? 0 : vmax,
            vmin == INT_MAX ? 0 : vmin};
}