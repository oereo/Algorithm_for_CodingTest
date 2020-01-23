// n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
// 사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
// 각 숫자는 1 이상 50 이하인 자연수입니다.
// 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int result = 0;
int cnt = 0;
int b = 1;
int ans = 0;

void DFS(int cnt,int length, int value, int target, vector<int> &numbers){
    
    if(length == cnt){
        if(value == target){
    
            ans++;
         }
     return;   
    }
    
    
     DFS(cnt+1,length, value+numbers[cnt], target, numbers);
     DFS(cnt+1,length, value-numbers[cnt], target, numbers);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int length = numbers.size();
    //int plus_cnt = numbers.size()-1;
    //int minus_cnt = 1;
        
    DFS(1,length, numbers[0], target, numbers);
    DFS(1,length, 0 - numbers[0], target, numbers);
    
    answer = ans;
    
    return answer;
}