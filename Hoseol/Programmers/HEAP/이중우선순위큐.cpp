#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
   int len=operations.size();
    for(int i=0;i<len;i++)
    {
        if(operations[i].front()=='I')
        {
            int siz=operations[i].size();
            string temp="";
            for(int j=1;j<siz;j++)
            {
                temp+=operations[i].at(j);
            }
            //cout<<atoi(temp.c_str())<<"삽입"<<endl;
            answer.push_back(atoi(temp.c_str()));
        }
        if(!answer.empty()){
        if(operations[i].front()=='D')
        {
          
            if(operations[i][2]=='1')
            {
                //cout<<*max_element(answer.begin(),answer.end())<<"최대삭제"<<endl;
                answer.erase(max_element(answer.begin(),answer.end()));    
            }
            else
            {
               // cout<<*min_element(answer.begin(),answer.end())<<"최소삭제"<<endl;
                answer.erase(min_element(answer.begin(),answer.end()));   
            }
        }    
        }
    }
    vector<int> ans;
    if(answer.size()==0)
    {
        ans.push_back(0);
         ans.push_back(0);
    }
    else
    {
        ans.push_back(*max_element(answer.begin(),answer.end()));
        ans.push_back(*min_element(answer.begin(),answer.end()));
    }
    return ans;
}