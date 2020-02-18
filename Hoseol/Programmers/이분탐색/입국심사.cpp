#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long MAX;
long long MIN=1000000000;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    int len=times.size();
    for(int i=0;i<len;i++)
    {
        MAX=max(MAX,(long long)times[i]);
        MIN=min(MIN,(long long)times[i]);
    }
    int k=(n/len);
    if(k==0){k=1;}
    long long low=MIN*k;
    long long high=MAX*k;
    answer=high;
    long long mid;
    while(low<=high)
    {
        mid=(high+low)/2;
       
      
        long long temp=0;
        for(int i=0;i<len;i++)
        {
           temp+=(mid/(long long)times[i]);
        }
        if(temp>=n)
        {
            high=mid-1;
            answer=min(answer,mid);
        }
        else {
            low=mid+1;    
        }
        
    }
    
    return answer;
}