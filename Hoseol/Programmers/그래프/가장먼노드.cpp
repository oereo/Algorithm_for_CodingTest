#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> map[20001];
int visited[20001];

queue<int> q;
int MAX=-999;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int len=n;
    int len_edge=edge.size();
    for(int i=0;i<len_edge;i++)
    {
        map[edge[i][0]-1].push_back(edge[i][1]-1);
        map[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    q.push(0);
    visited[0]=1;
    int tmp; int len2; int key=1;  int siz=0;
    while(!q.empty())
    {
        for(int k=0;k<siz;k++)
        {
        tmp=q.front();
        q.pop();
        len2=map[tmp].size();
       
       
        for(int i=0;i<len2;i++)
        {
            if(visited[map[tmp][i]]==0)
            {
                visited[map[tmp][i]]=key;
                q.push(map[tmp][i]);
               
            }
            
        }
        }
        
        siz=q.size();
        key++;
        
    }
    for(int i=0;i<n;i++)
    {
      
      MAX=max(MAX,visited[i]);
    }
     
    for(int i=0;i<n;i++)
    {
      
        if(visited[i]==MAX)
        {
            answer++;
        }
    }
    
    
    return answer;
}