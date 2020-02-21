#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct print{
    int priority;
    bool target=false;
};
vector<print> printer;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int len=priorities.size();
    for(int i=0;i<len;i++)
    {
        print temp;
        temp.priority=priorities[i];
        if(location==i)
        {
            temp.target=true;
        }
        printer.push_back(temp);
    }
    int cnt=0;
    
    //  for(int i=0;i<len;i++)
    // {
    //         cout<<printer[i].priority<<":"<<printer[i].target<<endl;
    // }
    
    
    
    while(1)
    {
        print t=printer.front();
        int length=printer.size();
        bool check=true;
        for(int i=0;i<length;i++)
        {
            if(printer[i].priority>t.priority)
            {
             check=false;
                printer.push_back(t);
                printer.erase(printer.begin(),printer.begin()+1);
             break;
            }
        }
        if(check)
        {
            printer.erase(printer.begin(),printer.begin()+1);
            cnt++;
            if(t.target)
            {
            break;
            }
        }


    }
    
    
    
    return cnt;
}