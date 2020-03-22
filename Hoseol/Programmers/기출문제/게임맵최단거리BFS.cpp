#include<vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point{
    int a;
    int b;
    int key;
};
queue<point> BFS;
int map2[101][101]={1,};
int solution(vector<vector<int> > maps)
{
	int answer = 0;
    int len1=maps.size();
    int len2=maps[0].size();
    int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
    point first;
    first.a=0; first.b=0; first.key=1; int cnt=2;
    BFS.push(first);
    while(!BFS.empty())
    {
        int siz=BFS.size();
        point temp=BFS.front();
        if(temp.a==len1-1&&temp.b==len2-1)
        {
            return temp.key;
        }  
        BFS.pop();
        for(int i=0;i<4;i++)
        {
            if((temp.a+dir[i][0]>=0&&temp.a+dir[i][0]<len1)&&(temp.b+dir[i][1]>=0&&temp.b+dir[i][1]<len2))
            {  
                if(map2[temp.a+dir[i][0]][temp.b+dir[i][1]]==0&&maps[temp.a+dir[i][0]][temp.b+dir[i][1]]==1)
                {
                    point p;
                    p.a=temp.a+dir[i][0];
                    p.b=temp.b+dir[i][1];
                    p.key=temp.key+1;
                    map2[temp.a+dir[i][0]][temp.b+dir[i][1]]=p.key;
                    BFS.push(p);
                }
            }
        }
        cnt++;
    }
	return -1;
}