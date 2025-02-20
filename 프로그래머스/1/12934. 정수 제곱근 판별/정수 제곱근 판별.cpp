#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    answer = -1;
    for(int i=1;i<=sqrt(n);i++){
        if(pow(i,2)==n){
            answer=pow(i+1,2);
            break;
        }
    }
    
    return answer;
}