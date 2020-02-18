#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;
priority_queue<int, vector<int>,greater<int>> min_heap;
int solution(vector<int> scoville, int K) {
    int answer = -1;
    int len=scoville.size();
    for(int i=0;i<len;i++)
    {
        min_heap.push(scoville[i]);
    }
    long a1,a2;
   a2=0;
   
    while(len>=1)
    {   
         a1=min_heap.top();
            min_heap.pop();
            len--;
        if(len==0)
        {
            if(a1>=K)
            {
            answer=a2;
            break;
            }
            
            else
            {
                break;
            }
        }
        if(a1<K)
        {
        a1+=2*min_heap.top();
        
        min_heap.pop();
        min_heap.push(a1);
        a2++;
        }
        else
        {
            answer=a2;
            break;
        }
        
    }
    
    return answer;
}