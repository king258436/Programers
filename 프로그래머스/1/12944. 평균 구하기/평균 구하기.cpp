#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int size = arr.size();
    long long sum=0;
    for(int a : arr){
        sum +=a;
    }
    answer = (double)sum/(double)size;
    return answer;
}