
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int nearest[101];
int dist[101];
int map[101][101];
int used[101];
int solution(int n, vector<vector<int>> costs) {
    int len=costs.size();
    for(int i=0;i<len;i++)
    {
      map[costs[i][0]][costs[i][1]]=costs[i][2];
      map[costs[i][1]][costs[i][0]]=costs[i][2];
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         if(i!=j&&map[i][j]==0)
         {
            map[i][j]=999999;
         }
      }
    }
    int answer = 0;
    int vnear=0;
    dist[vnear]=999999;
    used[0]=1;
    for(int i=1;i<n;i++)
    {
       nearest[i]=0; 
       dist[i]=map[i][0];
       if(dist[i]<dist[vnear])
       {
          vnear=i;
       }
    }
    answer+=dist[vnear];
    used[vnear]=1;
    dist[vnear]=999999;
    for(int i=2;i<n;i++)
    {
       int minest=vnear;
      for(int j=0;j<n;j++)
      {

         if(used[j]==0)
         {
             dist[j]=min(dist[j],map[j][vnear]);
             if(dist[j]<=dist[minest])
             {
                minest=j;
             }
         }      
      }
      vnear=minest;  
      answer+=dist[vnear];
      used[vnear]=1;
      dist[vnear]=999999;   
    }
    return answer;
}