#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
using namespace std;
vector<string> num;
bool cmp(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    int len=numbers.size();
    for(int i=0;i<len;i++)
    {
        num.push_back(to_string(numbers[i]));    
    }
    sort(num.begin(),num.end(),cmp);
    if(num[0]=="0")
    {
        return "0";
    }
     for(int i=0;i<len;i++)
    {
        answer+=num[i];    
    }
    
    
    return answer;
}