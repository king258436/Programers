#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<bool> check(1000);
    int s = numbers.size();
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(check[numbers[i]+numbers[j]]==false){
                answer.push_back(numbers[i]+numbers[j]);
                check[numbers[i]+numbers[j]]=true;
            }
        }
        
    }
    sort(answer.begin(),answer.end());
    return answer;
}