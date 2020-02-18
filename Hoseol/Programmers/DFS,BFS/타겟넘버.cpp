#include <string>
#include <vector>

using namespace std;
int cnt;

void DFS(int plus, int minus, int a ,vector<int> k,int ans,int tar)
{
    if(plus+minus==k.size())
    {
        if(ans==tar)
        {
            cnt++;
           
        }
        return;
    }
    DFS(plus+1,minus,a+1,k,ans+k[a+1],tar);
    DFS(plus,minus+1,a+1,k,ans-k[a+1],tar);
    
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(1,0,0,numbers,numbers.front(),target);
    DFS(0,1,0,numbers,-numbers.front(),target);
    answer=cnt;    
    return answer;
}