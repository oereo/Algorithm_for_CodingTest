#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
int map2[101][101];
int len1;
int len2;
int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};

void DFS(int a, int b , int cnt, vector<vector<int> > maps)
{
    map2[a][b]=cnt;
    for(int i=0;i<4;i++)
    {
        if((a+dir[i][0]>=0&&a+dir[i][0]<len1)&&(b+dir[i][1]>=0&&a+dir[i][1]<len2))
        {
            if(map2[a+dir[i][0]][b+dir[i][1]]==0||cnt<map2[a+dir[i][0]][b+dir[i][1]])
            {
                if(maps[a+dir[i][0]][b+dir[i][1]]==1)
                {
                DFS(a+dir[i][0],b+dir[i][1],cnt+1,maps);
                }
            }
        }
    
    }
    
    

}
int solution(vector<vector<int> > maps)
{
	int answer = 0;
    len1=maps.size();
    len2=maps[0].size();
    DFS(0,0,1,maps);
    if(map2[len1-1][len2-1]==0)
    {
        answer=-1;
    }
    else
        answer=map2[len1-1][len2-1];
    
	return answer;
}






