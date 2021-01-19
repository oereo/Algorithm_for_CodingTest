#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int st_len = skill_trees.size();
    int skill_len = skill.size();
    int answer = st_len;
    for(int i = 0; i < st_len; i++){
        vector<int> idx(skill_len);
        for(int j = 0; j < skill_len; j++){
            idx[j] = skill_trees[i].find(skill[j]);
            
            // 존재하지 않는 경우
            if(idx[j] == -1)    
                idx[j] = 100;
            
            // idx 벡터가 오름차순이어야 함
            if(j - 1 < 0) continue;
            if(idx[j - 1] > idx[j]){
                answer--;
                break;
            }
        }
    }
    return answer;
}