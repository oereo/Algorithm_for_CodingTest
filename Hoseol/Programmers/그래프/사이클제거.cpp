#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int visited[100];
int map[5001][5001];
int map_copy[5001][5001];
int cmp1;
int cmp2;
void deleteNode(int n,int size)
{
    for(int i=0;i<=size;i++)
    {
      map_copy[n][i]=0;
      map_copy[i][n]=0;  
    }
}
void visitedRe(int size)
{
    for(int i=0;i<size;i++)
    {
       visited[i]=0;
    }
}
void reNode(int n,int size)
{
     for(int i=0;i<=size;i++)
    {
      map_copy[n][i]=map[n][i];
      map_copy[i][n]=map[i][n];  
    }
    cmp2=0;
}

bool findCycleAlgorithm(int here,int size,int from) {
    if (visited[here] == -1) {
        
      return true;
    }
  visited[here] = -1;
  for (int there =0; there<size;there++)
  { if(there==from) {continue;}
    if(map_copy[here][there]==1){  
    if (findCycleAlgorithm(there,size,here)) {
      return true;
    }
    }
  }
  visited[here] = 1;
  return false;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    int len =edges.size();
    cmp1=-1;
    for(int i=0;i<len;i++)
    {
      map[edges[i][0]-1][edges[i][1]-1]=1;  
      map[edges[i][1]-1][edges[i][0]-1]=1; 
      map_copy[edges[i][0]-1][edges[i][1]-1]=1;  
      map_copy[edges[i][1]-1][edges[i][0]-1]=1;   
      cmp1=max(cmp1,max(edges[i][0],edges[i][1]));
    }
       
        len=cmp1;
        deleteNode(0,len);
        if(!findCycleAlgorithm(1,len,1))
        {
            answer+=1;
            cout<<answer<<endl;
        }
        reNode(0,len);
     visitedRe(len);
    for(int i=1;i<len;i++)
    {
        deleteNode(i,len);
        if(!findCycleAlgorithm(0,len,0))
        {
            answer+=(i+1);
            cout<<answer<<endl;
        }
        reNode(i,len);
        visitedRe(len);
    }
 
 
    return answer;
}