#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int s = elements.size();
    set<int> set;
    for(int i=1;i<=s;i++){// 더할 수열 개수
        
        for(int st=0;st<s;st++){// 수열 시작 부분
            long long sum=0;
            for(int j=st;j<st+i;j++){
                sum+=elements[j%s];
            }
            set.insert(sum);
        }
    }
    answer= set.size();
    return answer;
}