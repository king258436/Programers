#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(int k, vector<int> tangerine) {
    // 크기별 귤의 개수를 세기 위한 해시맵
    unordered_map<int, int> sizeCount;
    for(auto size : tangerine){
        sizeCount[size]++;
    }
    
    // 귤의 개수를 내림차순으로 정렬하기 위한 벡터
    vector<int> counts;
    for(auto &pair : sizeCount){
        counts.push_back(pair.second);
    }
    
    sort(counts.begin(), counts.end(), greater<int>());
    
    int totalSelected = 0; // 선택한 귤의 총 개수
    int distinctSizes = 0; // 선택한 서로 다른 크기의 수
    
    // 가장 많은 귤부터 선택하여 k개 이상이 될 때까지 반복
    for(auto count : counts){
        totalSelected += count;
        distinctSizes++;
        if(totalSelected >= k){
            break;
        }
    }
    
    return distinctSizes;
}
