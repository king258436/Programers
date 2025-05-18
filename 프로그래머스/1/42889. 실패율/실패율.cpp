#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<double,int>&a, pair<double,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> vec;
        int size = stages.size();
    for(int i=1;i<=N;i++){
        int cnt=0;
        for(int j=0;j<stages.size();j++){
            if(i==stages[j]){
                cnt++;
            }
        }
        if(size == 0){
            vec.push_back({0,i});
            continue;
        }
        vec.push_back({(double)cnt/size,i});
        size-=cnt;
        
    }
    sort(vec.begin(),vec.end(),cmp);

    for(int i=0;i<vec.size();i++){
        answer.push_back({vec[i].second});
    }
    return answer;
}