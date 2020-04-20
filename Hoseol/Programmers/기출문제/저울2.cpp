#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<int> weight) {
    int answer = 0;
    int len= weight.size();
    sort(weight.begin(),weight.end());
    int sum=0;
    if(weight[0]!=1){return 1;}
    sum=1;
    for(int i=1;i<len;i++)
    {
        sum+=weight[i];
        if(i==len-1){return sum+1;}
        if(i+1<len&&sum<weight[i+1])
        {
            return sum+1;
        }     
    }
}

//셔틀 버스, 베스트 엘범//  
