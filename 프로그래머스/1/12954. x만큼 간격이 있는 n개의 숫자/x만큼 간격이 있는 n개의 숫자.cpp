#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    n--;
    answer.push_back(x);
    for(int i=0;i<n;i++){
        answer.push_back(answer[i]+x);
    }
    return answer;
}