#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
map<string, int> nameToIdx;// map[이름] = 인덱스 번호
map<string, int> nameToFactor; // map[이름] = 이번달 주고받은 선물 점수
int arr[50][50];

void init(vector<string> &friends) {// (초기화) friends 에 있는 모든 이름에 번호를 부여. 0부터
    int idx = 0;
    for (string name: friends) {
        nameToIdx[name] = idx++;
    }
}


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    init(friends);
    vector<int> v(friends.size(), 0);
    for (string gift: gifts) {
        istringstream iss(gift);
        string name1, name2;

        iss >> name1 >> name2;

        nameToFactor[name1]++;
        nameToFactor[name2]--;

        arr[nameToIdx[name1]][nameToIdx[name2]]++;
    }
    int size = friends.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i][j] > arr[j][i]) {
                v[i]++;
            }
            else if (arr[i][j] < arr[j][i]) {
                v[j]++;
            }
            else {
                string name1 = friends[i];
                string name2 = friends[j];
                if(nameToFactor[name1]>nameToFactor[name2]){
                    v[i]++;
                }
                else if(nameToFactor[name1]<nameToFactor[name2]){
                    v[j]++;
                }
            }
        }
    }
    for(int element : v){
        answer = max(answer,element);
    }
    return answer;
}