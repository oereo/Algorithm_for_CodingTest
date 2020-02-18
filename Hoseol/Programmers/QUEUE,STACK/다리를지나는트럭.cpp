#include <string>
#include <vector>
#include <iostream>
using namespace std;
int bridgeTruck[10001];// 버스시간
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time=0;
    int passed=0;
    int len=truck_weights.size();
    int i=0;//현재 올라간 버스들
    while(1)
    {
        if(bridgeTruck[len-1]==-99)
        {
            break;
            
        }
        
        for(int j=passed;j<=i;j++) //이미지나간 버스빼고 ,현재 교량위에있는 버스들 
        {
            if(bridgeTruck[j]>0)
            {
            bridgeTruck[j]--;
                if(bridgeTruck[j]==0)
                {
                    bridgeTruck[j]=-99;
                    weight+=truck_weights[j];
                        passed++; //지나간놈
                }
            }
        }
        
        if(weight>=truck_weights[i])
        {
            weight-=truck_weights[i];
            bridgeTruck[i]=bridge_length;
            i++;
        }
        time++;
    }
    return time;
}