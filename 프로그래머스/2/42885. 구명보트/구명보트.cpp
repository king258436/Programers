#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int size = people.size();
    int sum = 0;
    int start = 0, end = size - 1;
    while (start <= end) {
        int sum = people[start] + people[end];
        if (start == end) {
            answer++;
            break;
        }
        if (sum <= limit) {
            start++;
            end--;
        } else {
            end--;
        }

        answer++;
    }
    return answer;
}