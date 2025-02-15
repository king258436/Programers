#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int Min= min(a,b);
    int Max= max(a,b);
    for(int i=Min;i<=Max;i++){
        answer+=i;
    }
    return answer;
}