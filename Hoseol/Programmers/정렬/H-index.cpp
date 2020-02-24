#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int len=citations.size();
    int high=-10000;
    for(int i=0;i<len;i++)
     {
        high=max(high,citations[i]);
     }
    int low=0;
  
    int h=0;
    while(1)
    {
        h=(low+high)/2;
        cout<<"high:"<<high<<"low:"<<low<<"h:"<<h<<endl;
        if(h==low){break;}
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(h<=citations[i])
            {
                cnt++;
               
            }
        }
      
        if(cnt>=h)
        {
            low=h;
        }
        else
        {
            high=h;
        }
    
    }
    answer=low;
    
    return answer;
}