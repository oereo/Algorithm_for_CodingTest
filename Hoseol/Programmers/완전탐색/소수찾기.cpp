#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int answer = 0;
int used[100];
vector<int> ans;
void prime(int a)
{
    
   
    if(a<2)
    {
        return;
    }
    
    for(int i=2;i<=a;i++)
    {
     if(a%i==0&&i!=a)
     {
        return;
     }
    }   
    answer++;   
}
void DFS(int size, int len,string t, string numbers)
{
    
    if(t.length() == size)
    {
        ans.push_back(atoi(t.c_str()));
        return;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(used[i]==0)
            {
                t+=numbers[i];
                used[i]=1;
                DFS(size,len,t,numbers);
                t.erase(t.end()-1,t.end());
                used[i]=0;
            }
        }
        
    }
    
}


int solution(string numbers) {
    int len=numbers.length();
 
    for(int time=1;time<=len;time++)
    {
        for(int i=0;i<len;i++)
        {
            string temp="";
            temp+=numbers[i];
            used[i]=1;
            DFS(time,len,temp,numbers);
            used[i]=0;
        }
       
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0;i<ans.size();i++)
    {
      prime(ans[i]);
      cout<<ans[i]<<" ";
    }
    
    
    return answer;
}