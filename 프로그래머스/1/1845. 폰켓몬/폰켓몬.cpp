#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> m;
    for(int n :nums){
        m.insert({n,1});
    }
    if(m.size()>=nums.size()/2){
        answer=nums.size()/2;
    }
    else{
        answer= m.size();
    }
    
    return answer;
}