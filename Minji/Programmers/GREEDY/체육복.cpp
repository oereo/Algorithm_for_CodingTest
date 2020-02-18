#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    
    for(iter1=lost.begin(); iter1 != lost.end(); iter1++){
        for(iter2=reserve.begin(); iter2 != reserve.end(); iter2++){
            if(*iter1 == *iter2){
                answer++;
                lost.erase(iter1);
                reserve.erase(iter2);
                iter1--;
                break;
            }
        }
    }
    
    for(int i : lost){
        for(iter2=reserve.begin(); iter2 != reserve.end(); iter2++){
            if(i - 1 == *iter2){
                answer++;
                reserve.erase(iter2);       
                break;
            } else if(i + 1 == *iter2){
                answer++;
                reserve.erase(iter2);
                break;
            }
        }
    }
    return answer;
}
