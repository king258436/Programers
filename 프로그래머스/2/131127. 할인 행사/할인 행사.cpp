#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool Check(const map<string, int>& WantAndNumber)
{
    for(auto ele : WantAndNumber)
    {
        if(ele.second != 0)
        {
            return false;
        }
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int size = discount.size();
    map<string, int> WantAndNumber;

    if(size < 10) return 0;

    for(int i = 0; i < want.size(); i++)
    {
        WantAndNumber[want[i]] = number[i];
    }

    for(int i = 0; i < 10; i++)
    {
        if(WantAndNumber.find(discount[i]) != WantAndNumber.end())
        {
            --WantAndNumber[discount[i]];
        }
    }

    answer += (int)Check(WantAndNumber);

    for(int i = 1; i <= size - 10; i++)
    {
        if(WantAndNumber.find(discount[i - 1]) != WantAndNumber.end())
        {
            ++WantAndNumber[discount[i - 1]];
        }

        if(WantAndNumber.find(discount[i + 9]) != WantAndNumber.end())
        {
            --WantAndNumber[discount[i + 9]];
        }

        answer += (int)Check(WantAndNumber);
    }

    return answer;
}