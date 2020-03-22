#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len =skill_trees.size();
    for(int i=0;i<len;i++)
    {
        int ptr1=0;
        int cmp=0;
        int ans_cmp=0;
        int len2=skill.size();
        int length=skill_trees[i].size();
        for(int j=0;j<len2;j++)
        {
          for(int k=0;k<length;k++)
          {
            if(skill[j]==skill_trees[i][k])
            {
                cmp++;
            }
          }
        }
        for(int j=0;j<length;j++)
        {
            if(skill[ptr1]==skill_trees[i][j])
            {
                ans_cmp++; ptr1++; 
            }
        }
        if(ans_cmp==cmp)
        {
            answer++;
        }
    }
    
    return answer;
}