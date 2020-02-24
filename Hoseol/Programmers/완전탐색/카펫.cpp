#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int size=brown+red; //xy
    //x+y=brown/2+2
    for(int i=1;i<size;i++)
    {
        int x=i;
        if(size%x==0)
        {
            int y=size/x;
            if(x+y==(brown/2)+2)
            {
                answer.push_back(y);
                answer.push_back(x);
            }
            
        }
    
    }
    
    
    return answer;
}