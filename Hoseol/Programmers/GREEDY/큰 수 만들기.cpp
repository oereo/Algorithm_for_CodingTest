#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
long ans;
string solution(string number, int k) {
    string answer = "";
    ans=atoi(number.c_str());
    int len=number.length();
   int j=-1; int i=0; int h=0;
 while(1){
   char M='0'; 
   for(int i=j+1;i<len-(len-k-1)+h;i++)
   {
        if(M<number[i])
        {
            M=number[i];
            j=i;
            
        }
   }
     h++;
   
   answer+=M;
     if(answer.length()==len-k)
     {break;
    }
 }
       

    return answer;
}