#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int visited[51];
queue<string> BFS;
int length;


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int len=words.size();
    int len_word=words[0].size();
    BFS.push(begin);
    int count=0;
    while(!BFS.empty())
    {  
        int time=BFS.size();
        for(int k=0;k<time;k++)
        {
            string temp=BFS.front();
            BFS.pop();
           // cout<<temp<<endl;
            if(target==temp)
            {
                //cout<<"!!";
                answer=count;
                break;
            }
            else if(count==len)
            {
                answer=0;
                break;
            }

            for(int i=0;i<len;i++)
            {
                int cnt=0;
                for(int j=0;j<len_word;j++)
                {
                    if(temp[j]==words[i][j])
                    {
                        cnt++;
                    }
                }
                if(cnt==len_word-1&&visited[i]==0)
                {

                   // cout<<words[i]<<endl;
                    visited[i]=1;
                    BFS.push(words[i]);
                }

            }
   
  //  cout<<count<<":"<<endl;
    }
    count++;
}
    return answer;
}