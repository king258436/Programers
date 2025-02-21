#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum=0;
    int cpy=x;
    while(cpy){
        sum+=cpy%10;
        cpy/=10;
    }
    if(x%sum!=0) answer=false;
    return answer;
}