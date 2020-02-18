#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool check(int n){
    if(n<2)
        return false;
    for(int i = 2; i < n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;
    unordered_set<int> all_num;
    int len = numbers.size();
    
    for(char a : numbers){
        num.push_back(a-'0');
        all_num.insert(a-'0');
    }
    sort(num.begin(), num.end());
    do{
        for(int i = 2; i <= len;i++){
            string a = "";
            for(int j  = 0 ; j<i; j++)
                a += num[j] + '0';
            all_num.insert(stoi(a));
        }
    }while(next_permutation(num.begin(), num.end()));
    
    for(int n : all_num){   // 소수인 경우 answer++
        if(check(n))
            answer++;
    }
    return answer;
}
