#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        int sh = i/n;
        int re = i%n;
        answer.push_back(max(sh,re)+1);
    }
    return answer;
}