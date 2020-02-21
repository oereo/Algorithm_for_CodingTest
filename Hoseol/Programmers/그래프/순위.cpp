#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
int map[101][101];
int ans[100];
using namespace std;
void map_fetch(int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i!=j)
            {
                map[i][j]=999999;
            }
        }
    }
}
void floyd(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }

}
void show_map(int k)
{
for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
           
                cout<<map[i][j]<<" ";
            
        }
    cout<<endl;
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int len=results.size();
    map_fetch(n);
    for(int i=0;i<len;i++)
    {
        map[results[i][1]-1][results[i][0]-1]=1;
    }
     show_map(n);
    cout<<endl;
    floyd(n);
    show_map(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]==999999)
            {
                if(map[j][i]==999999)
                {
                    ans[i]=-1;
                }
            }
        }
        if(ans[i]==0)
        {
            answer++;
        }
        
    }
    return answer;
}