/*
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

예:
participant	                            completion	                        return
[leo, kiki, eden]	                    [eden, kiki]	                    leo
[marina, josipa, nikola, vinko, filipa]	[josipa, filipa, marina, nikola]	vinko
[mislav, stanko, mislav, ana]	        [stanko, ana, mislav]	            mislav
*/

#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> m; 

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for(int i = 0; i < completion.size(); i++){
        m[completion[i]] += 1;    
    }

    for(int i = 0; i < completion.size(); i++){
        if(m.find(participant[i]) == m.end()){
            return participant[i];
        }
        else{
            m[participant[i]] -= 1;
            if(m[participant[i]] < 0){
                return participant[i];
            }
        }
    }

    return answer;
}