#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    int len = numbers.size();
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            s.insert(numbers[i]+numbers[j]);
        }
    }
    vector<int> answer(s.begin(),s.end());
    
    return answer;
}