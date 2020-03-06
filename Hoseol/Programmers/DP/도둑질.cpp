#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct house{
    int a=0;
    int b=0;
};
house DP1[1000001];
house DP2[1000001];
//10 2 2 100 2 case 고려
int solution(vector<int> money) {
    DP1[0].a=money[0];
    DP1[1].a=money[1]; DP2[1].a=money[1];
    DP1[1].b=money[1]; DP2[2].b=money[2];
    DP1[2].a=DP1[0].a+money[2]; DP2[2].a=money[2];
    DP1[2].b=money[2]; DP2[2].b=money[2];
    int ans1=0; int ans2=0;
    ans1=max(DP1[1].a,DP1[2].a); ans2=max(DP2[1].a,DP2[2].a);
    int len=money.size();
    for(int i=3;i<len;i++)
    {
        if(i<len-1){
        DP1[i].a=max(DP1[i-2].a,DP1[i-2].b)+money[i];
        DP1[i].b=max(DP1[i-3].a,DP1[i-3].b)+money[i];
        ans1=max(ans1,max(DP1[i].a,DP1[i].b));
        }
        DP2[i].a=max(DP2[i-2].a,DP2[i-2].b)+money[i];
        DP2[i].b=max(DP2[i-3].a,DP2[i-3].b)+money[i];
        ans2=max(ans2,max(DP2[i].a,DP2[i].b));
    }
    
    int answer=max(ans1,ans2);
    return answer;
}