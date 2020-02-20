#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ticket_used[10001];
string ans[5][10001];
vector<string> A;
int ptr;
bool C=true;
vector<string> answer;
void DFS(int start, int size, vector<vector<string>> tickets, string dest)
{
if(size>=tickets.size())
{
    if(ptr<=4){
    for(int i=0;i<A.size();i++)
    {
     ans[ptr][i]=A[i];   
    }
    ptr++;
    }
    return;
}
    for(int i=0;i<tickets.size();i++)
    {
        if(ticket_used[i]==0&&dest==tickets[i][0])
        {
          A.push_back(tickets[i][1]);
          ticket_used[i]=1;
          DFS(i,size+1, tickets,tickets[i][1]);
          ticket_used[i]=0;
          A.pop_back();     
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    int len=tickets.size();
    sort(tickets.begin(),tickets.end());
    A.push_back("ICN");
    for(int i=0;i<len;i++)
    {
        if(tickets[i][0]=="ICN")
        {
            A.push_back(tickets[i][1]);
            ticket_used[i]=1;
            DFS(i,1, tickets,tickets[i][1]);
            ticket_used[i]=0;
            A.pop_back();
        }
    }
 

 for(int j=0;j<=tickets.size();j++)
     {
          answer.push_back(ans[0][j]);
     }

       
  
    return answer;
}