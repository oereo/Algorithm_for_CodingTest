#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int len =routes.size();
    sort(routes.begin(),routes.end());
    int length=routes[0][1];
    answer++;
    for(int i=1;i<len;i++)
    {
        
      if(length>=routes[i][1])
      {
          length=routes[i][1];
      }
      if(length<routes[i][0])
      {
        answer++;
        length=routes[i][1];
           cout<<length<<endl;
      }
       
    }
    
    return answer;
}