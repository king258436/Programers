#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=yellow/2||i==1;i++){
        if(yellow%i!=0) continue;
        int height=i;
        int length=yellow/i;
        if(i*2+length*2+4 == brown){
            answer.push_back(length+2);
            answer.push_back(height+2);
            break;
        }
    }
    return answer;
}