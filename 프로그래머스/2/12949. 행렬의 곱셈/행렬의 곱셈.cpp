#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int s = arr1.size();
    for(int i=0;i<s;i++){
        int s2= arr2[0].size();
        vector<int> vec;
        for(int j=0;j<s2;j++){
            int e=0;
            int s3= arr2.size();
            for(int k=0;k<s3;k++){
                e+=arr1[i][k]*arr2[k][j];
            }
            vec.push_back(e);
        }
        answer.push_back(vec);
    }
    return answer;
}