#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(vector<int> arr) {
    long long answer = 0;
    int maX=0;
    int size=arr.size();
    for(int a : arr){
        maX=max(maX,a);
    }
    int i=maX;
    while(1){
        bool flag=0;
        for(int a: arr){
            if(i%a!=0){
                flag=true;
                break;
            }
        }
        if(!flag){
            answer= i;
            break;
        }
        i++;
    }
    return answer;
}