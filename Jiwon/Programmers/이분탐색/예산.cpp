/*
국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것입니다. 
국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있습니다. 
그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정합니다.

1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정합니다.
2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정합니다. 
   상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정합니다.

예:
budgets	                M	return
[120, 110, 140, 150]	485	127
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    long budgetstotal = 0;
    sort(budgets.begin(), budgets.end());
    for(int i = 0; i < budgets.size(); i++){
        budgetstotal += budgets[i];
    }
    int left = 0, right = 100000, mid = 0;
    if( M > budgetstotal){
        answer = budgets[budgets.size()-1];
    }
    else{
        while(left + 1 < right){
            mid = (right + left) / 2;
            budgetstotal = 0;
            for(int i = 0 ; i < budgets.size(); i++){
                if( mid > budgets[i]){
                    budgetstotal += budgets[i];
                }
                else{
                    budgetstotal += mid;
                }
            }
            if(budgetstotal > M){
                right = mid;
            }
            else{
                left = mid;
            }
        }   
        answer = left;    
    }
    return answer;
}