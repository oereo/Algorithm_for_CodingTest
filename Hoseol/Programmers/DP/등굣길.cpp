#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct point{
    int a;
    int b;
};
long long DP[101][101];
queue<point> q;
int visited[101][101];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

using namespace std;



int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int len=puddles.size();
    for(int i=0;i<len;i++)
    {
      DP[puddles[i][1]-1][puddles[i][0]-1]=-1;
    }
    point first;
    DP[n-1][m-1]=1;
    first.a=n-1; first.b=m-1; q.push(first);
    visited[n-1][m-1]=1;
    while(!q.empty())
    {
         point t= q.front();
            if(t.a==0&&t.b==0)
            {
                break;
            }
       
        int length=q.size();
        for(int i=0;i<length;i++)
        {   point t= q.front();
            if(t.a==0&&t.b==0)
            {
                break;
            }
            q.pop();
            for(int i=0;i<4;i++)
            {
                if((t.a+dir[i][0]>=0&&t.a+dir[i][0]<n)&&(t.b+dir[i][1]>=0&&t.b+dir[i][1]<m))
                {
                    if(DP[t.a+dir[i][0]][t.b+dir[i][1]]!=-1){
                    if(dir[i][0]==-1||dir[i][1]==-1)
                    {
                        DP[t.a+dir[i][0]][t.b+dir[i][1]]+=DP[t.a][t.b];
                        DP[t.a+dir[i][0]][t.b+dir[i][1]]%=1000000007;
                    }
                    if(visited[t.a+dir[i][0]][t.b+dir[i][1]]==0)
                    {
                        visited[t.a+dir[i][0]][t.b+dir[i][1]]=1;
                        point s;
                        s.a=t.a+dir[i][0];
                        s.b=t.b+dir[i][1];
                        q.push(s);

                    }
                    }
                }    
            }
                
        }
            
            
    }
    answer=(DP[0][0]%1000000007);
    
    
    return answer;
}