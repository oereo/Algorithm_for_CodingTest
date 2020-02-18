#include <string>
#include <vector>

using namespace std;
int student[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lost_len=lost.size();
    int reserve_len=reserve.size();
    for(int i=0;i<n;i++){student[i]=1;}
    for(int i=0;i<lost_len;i++){student[lost[i]-1]--;}
    for(int i=0;i<reserve_len;i++){student[reserve[i]-1]++;}
    for(int i=0;i<n;i++)
    {
        if(student[i]==0)
        {
            if(i>0&&student[i-1]==2)
            {
                student[i-1]--;
                student[i]++;
            }
            else if(i+1<n&&student[i+1]==2)
            {
                student[i+1]--;
                student[i]++;
            }
            
        }
        if(student[i]>=1)
        {
            answer++;
        }
    }
   
    
    return answer;
}