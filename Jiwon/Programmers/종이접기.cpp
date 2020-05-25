/*
직사각형 종이를 n번 접으려고 합니다. 이때, 항상 오른쪽 절반을 왼쪽으로 접어 나갑니다.
종이를 모두 접은 후에는 종이를 전부 펼칩니다. 종이를 펼칠 때는 종이를 접은 방법의 역순으로 펼쳐서 처음 놓여있던 때와 같은 상태가 되도록 합니다. 
위와 같이 두 번 접은 후 종이를 펼치면 아래 그림과 같이 종이에 접은 흔적이 생기게 됩니다.
위 그림에서 ∨ 모양이 생긴 부분은 점선(0)으로, ∧ 모양이 생긴 부분은 실선(1)으로 표시했습니다.

종이를 접은 횟수 n이 매개변수로 주어질 때, 종이를 절반씩 n번 접은 후 모두 펼쳤을 때 생기는 접힌 부분의 모양을 배열에 담아 
return 하도록 solution 함수를 완성해주세요.

예:
n	result
1	[0]
2	[0,0,1]
3	[0,0,1,0,0,1,1]
0 0 1 0 0 1 1 0 0 0 1 1 0 1 1
*/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);

    //int power = pow(2,n);

    if(n == 1){
        return answer;
    }
    else{
        for(int i = 2; i <= n; i++){
            vector<int> dp;
            dp = answer;
            answer.push_back(0);
            for(int k = dp.size() - 1; k >= 0; k--){               
                if(dp[k] == 1){
                    answer.push_back(0);
                }
                else answer.push_back(1);
            }
        }
    }
    
    return answer;
}