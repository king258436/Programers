#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(1){
        
        if(a==b){
            break;
        }
        else{
            a= (a+1)/2;
            b= (b+1)/2;
        }
        answer++;
    }

    return answer;
}