#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
   int copy[101];
    int i;int j; int k;
    for(int a=0;a<commands.size();a++)
    {
        for(int b=0;b<array.size();b++)
        {
            copy[b]=array[b];
        }
        
          i=commands[a][0];
          j=commands[a][1];
          k=commands[a][2]-2+i;
        sort(copy+i-1,copy+j);
      
            answer.push_back(copy[k]);
        
       
        
        
    }

    
    

    return answer;
}