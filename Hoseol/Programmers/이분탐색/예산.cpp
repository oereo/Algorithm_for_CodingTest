#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int len=budgets.size();
    long sum;
    for(int i=0;i<len;i++)
    {
        sum+=budgets[i];
    }
    int low=0;
    long high=M;
    int mid;
    int answer;
    sort(budgets.begin(), budgets.end());
    if(sum<M)
    {
        answer=budgets[budgets.size()-1];
    }
    else
    {
    while(low+1<high)
    {
        mid=(high+low)/2;
        sum=0;
        for(int i=0;i<len;i++)
        {
            if(budgets[i]<mid)
            {sum+=budgets[i];
            }
            else
            {
                sum+=mid;
            }
            
        }
        if(sum>M)
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
        
    }
    answer=low;
    }
   
    return answer;
}