#include <string>
#include <vector>
#include <iostream>
using namespace std;
int map[201][201];
int checked[201];

int ans=1;
void DFS(int x, int num,int len)
{
    checked[x]=num;
    ans=num;
    for(int i=0;i<len;i++)
    {
            if(map[x][i]!=0&&checked[i]==0)
            {
                DFS(i,num,len);
            }         
    }
}



int solution(int n, vector<vector<int>> computers) {
    int len=computers.size();
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            map[i][j]=computers[i][j];
        }
    }
    for(int i=0;i<len;i++)
    {
        
            if(checked[i]==0)
            {
                DFS(i,ans,len);
                ans++;
            }            
        
    }
    
    
    int answer = ans-1;
    return answer;
}