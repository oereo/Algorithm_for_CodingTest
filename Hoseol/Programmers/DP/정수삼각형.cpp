#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int DP[500][500];


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    DP[0][0]=triangle[0][0];
    int len=triangle.size();
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            if(j==0)
            {
                DP[i][j]=DP[i-1][j]+triangle[i][j];
            }
            else if(j==i)
            {
                 DP[i][j]=DP[i-1][j-1]+triangle[i][j];   
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i-1][j-1])+triangle[i][j];
                
            }
        }
        
    }
    int MAX=-99;
    int len2=triangle[len-1].size();
    for(int i=0;i<len2;i++)
    {
        MAX=max(MAX,DP[len-1][i]);
    }
    answer=MAX;
    return answer;
}