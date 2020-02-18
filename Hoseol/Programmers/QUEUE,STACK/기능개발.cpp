#include <string>
#include <vector>
#include <iostream>
using namespace std;
int progress[101];
int speed[101];
int cnt;
int C;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; 
    int ss=progresses.size();
    for(int i=0;i<ss;i++)
    {
        progress[i]=progresses[i];
        speed[i]=speeds[i];
    }
    int front=0;
    while(cnt<ss)
    {
        if(progress[front]<100)
        {
            for(int i=front;i<ss;i++)
            {
                progress[i]+=speed[i];
            }
        }
        else
        {
            C=0;
            for(int i=front;i<ss;i++)
            {
                if(progress[i]>=100)
                {
                    C++;
                    cnt++;
                }
                else{
                    break;
                }
            }
            front+=C;
            answer.push_back(C);
            
        }
    
    }
    
    
   
    
    
    return answer;
}