#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int giveup(vector<int> ans, int key)
{
    int one[5]={1,2,3,4,5};
    int two[8]={2,1,2,3,2,4,2,5};
    int three[10]={3,3,1,1,2,2,4,4,5,5};
    int len=ans.size();
    int j=0;
    int return_num=0;
    switch (key)
    {
    case 1:
    {
          for(int i=0;i<len;i++)
        {
            if(j==5){ j=0;}
            if(ans[i]==one[j])
            {
              return_num++;  
            }
            j++;
        }
        return return_num;     
    } 
    case 2:
    {
            for(int i=0;i<len;i++)
        {
            if(j==8){ j=0;}
            if(ans[i]==two[j])
            {
              return_num++;  
            }
            j++;
        }
    return return_num;    
    }
    case 3:
    {
        for(int i=0;i<len;i++)
    {
        if(j==10){ j=0;}
        if(ans[i]==three[j])
        {
          return_num++;  
        }
        j++;
    }
    return return_num;    
        
    }
    
    }
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans;
     answer.push_back(giveup(answers,1));
     answer.push_back(giveup(answers,2)); 
     answer.push_back(giveup(answers,3)); 
     int MAX= -999;
    for(int i=0;i<3;i++)
    {
        MAX=max(MAX,answer[i]);
    }
    for(int i=0;i<3;i++)
    {
       if (MAX==answer[i])
       {
            ans.push_back(i+1);
       }
    }
    
return ans;
}