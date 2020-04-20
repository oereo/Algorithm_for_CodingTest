/*
이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.

명령어	수신 탑(높이)
I 숫자	큐에 주어진 숫자를 삽입합니다.
D 1	    큐에서 최댓값을 삭제합니다.
D -1	큐에서 최솟값을 삭제합니다.
이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 
모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.

예:
operations	        return
[I 16,D 1]	        [0,0]
[I 7,I 5,I -5,D -1]	[7,5]
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++){
        if(operations[i].front() == 'I'){
            string temp = "";
            for(int j = 1; j < operations[i].size(); j++){
                temp += operations[i].at(j);
            }
            answer.push_back(atoi(temp.c_str()));
        }
        if(!answer.empty()){
            if(operations[i].front() == 'D'){
                if(operations[i][2]== '1'){
                    answer.erase(max_element(answer.begin(),answer.end()));    
                }
                else{
                    answer.erase(min_element(answer.begin(),answer.end()));   
                }
            }    
        }
    }

    vector<int> tempnum;

    if(answer.size()==0){
        tempnum.push_back(0);
        tempnum.push_back(0);
    }
    else{
        tempnum.push_back(*max_element(answer.begin(),answer.end()));
        tempnum.push_back(*min_element(answer.begin(),answer.end()));
    }
    
    return tempnum;
}