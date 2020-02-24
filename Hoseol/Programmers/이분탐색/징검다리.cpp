#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    int MIN=1;
    int MAX=distance;
    int mid;
    while(MAX>=MIN)
    {
         mid=(MAX+MIN)/2;
       // cout<<MAX<<" "<<MIN<<" "<<mid<<endl;
        int prev=0;
        int cnt=0;
        for(int i=0;i<rocks.size();i++)
        {
            if(rocks[i]-prev<mid)
            {
               /// cout<<rocks[i]-prev<<" cnt++"<<endl;
                cnt++;
            }
            else{
                prev=rocks[i];
               // cout<<rocks[i]-prev<<endl;
            }
        }
       // cout<<"cnt:"<<cnt<<endl;
        if(cnt>n)
        {
            MAX=mid-1;
        }
        else
        {
            MIN=mid+1;
        }
    
    }
   
     
    
    
    return MAX;
}