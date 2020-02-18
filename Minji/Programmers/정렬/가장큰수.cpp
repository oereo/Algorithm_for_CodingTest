#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> copy_num;
bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    if(a.first == b.first){
        string ab = to_string(copy_num[a.second]) + to_string(copy_num[b.second]);
        string ba = to_string(copy_num[b.second]) + to_string(copy_num[a.second]);
        return ab > ba;
    }
    return a.first > b.first;    
}
 
string solution(vector<int> numbers) {
    // 최대값의 자리수(count) 구하기
    int count = 0;
    int max_num = *max_element(numbers.begin(),numbers.end());
    if(max_num == 0)
        return "0";
    while(max_num > 0){
        max_num /= 10;
        count++;
    }
    
    // 모든 숫자 자리수 맞춰주기(맨 앞의 숫자로 채우기)
    int len = numbers.size();
    vector<pair<string,int>> ans;
    for(int i = 0; i < len; i++) {
        ans.push_back(make_pair(to_string(numbers[i]),i));
        int size = ans[i].first.size();
        for(int j = size; j < count; j++)
            ans[i].first += ans[i].first[0];
    }
    
    // 정렬 후 원래 배열을 answer에 더해주기
    copy_num = numbers;
    sort(ans.begin(), ans.end(), cmp);
    string answer = "";
    for(int i = 0; i < len; i++)
        answer += to_string(numbers[ans[i].second]);
    return answer;
        
}
