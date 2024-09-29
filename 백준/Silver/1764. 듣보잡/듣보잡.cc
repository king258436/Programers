#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    vector<string> n_vec(n);
    vector<string> m_vec(m);
    vector<string> result;
    map<string,int> Map;
    for (int i = 0; i < n; i++) {
        cin>>n_vec[i];
        Map.insert({n_vec[i],1});
    }
    for(int i=0;i<m;i++){
        cin>>m_vec[i];
        if(Map.find(m_vec[i])!=Map.end()){
            result.push_back(m_vec[i]);
        }
    }
    int result_size= result.size();
    cout<< result.size()<<'\n';
    sort(result.begin(),result.end());
    for(int i=0;i<result_size;i++){
        cout<<result[i]<<'\n';
    }
    
}