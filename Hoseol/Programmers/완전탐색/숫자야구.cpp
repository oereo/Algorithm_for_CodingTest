#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
 // cout<<ans1[0]<<ans1[1]<<ans1[2]<<":"<<ans2[0]<<ans2[1]<<ans2[2]<<endl;
 //                     cout<<baseball[i][0]<<","<<baseball[i][1]<<","<<baseball[i][2]<<":"<<k<<","<<strike<<","<<ball<<endl;
using namespace std;
 int ans1[3];
 int ans2[3];
int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int len=baseball.size();
    for(int k=123;k<=987;k++)
    {
        bool okay=true;
        ans1[2]=k%10; 
        if(ans1[2]==0){continue;}
        
        ans1[1]=(k/10)%10; 
        if(ans1[1]==0){continue;}
        if(ans1[1]==ans1[2]){continue;}
        
        ans1[0]=k/100;
        if(ans1[0]==0){continue;}
        if(ans1[0]==ans1[1]||ans1[0]==ans1[2]){continue;}
       
        for(int i=0;i<len;i++)
        {
            int strike=0; int ball=0;
             ans2[2]=baseball[i][0]%10;
             ans2[1]=(baseball[i][0]/10)%10;
             ans2[0]=baseball[i][0]/100;
            for(int j=0;j<3;j++)
            {
                if(ans1[j]==ans2[j])
                {
                    strike++;
                }
            }
            if(strike!=baseball[i][1])
            { 
                 okay=false;
                 break;
            }
                
                if(ans1[0]==ans2[1]||ans1[0]==ans2[2])
                {
                    ball++;
                }
                 if(ans1[1]==ans2[0]||ans1[1]==ans2[2])
                {
                    ball++;
                }
                 if(ans1[2]==ans2[1]||ans1[2]==ans2[0])
                {
                    ball++;
                }
                 if(ball!=baseball[i][2])
                 {
                     okay=false;
                     break;
                 }

        }
        if(okay)
        {
            answer++;
        }
        
    }
    
    
    return answer;
}