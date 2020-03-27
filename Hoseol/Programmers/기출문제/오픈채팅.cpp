#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, string> M;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    int len=record.size();
    for(int i=0;i<len;i++)
    {
      int siz=record[i].size();
      if(record[i].substr(0,5)!="Leave")
      {   int ptr;
         if(record[i].substr(0,5)=="Enter"){ ptr=6;}
         else{ptr=7;}
        string temp;
        while(1)
        {
          if(record[i][ptr]==' ')
          {ptr++;break;}
          else{ temp+=record[i][ptr]; ptr++;}  
        }
        string temp2;
        while(1)
        {
          if(ptr==siz)
          {break;}
          else{ temp2+=record[i][ptr]; ptr++;}  
        }
        M[temp]=temp2;  
        cout<<temp<<":"<<M[temp]<<endl;                  
      }
     
    }
    //////////////////////
    for(int i=0;i<len;i++)
    {
       if(record[i].substr(0,6)=="Change")
       {
           continue;
       }   
        int siz=record[i].size();
        int ptr=6;
        string temp;
        while(1)
        {
          if(record[i][ptr]==' '||ptr==siz)
          {ptr++;break;}
          else{temp+=record[i][ptr]; ptr++;}  
        }
       string temp2=M[temp];
       if(record[i].substr(0,5)=="Enter")
       {
           temp2+="님이 들어왔습니다.";
       }
       else if(record[i].substr(0,5)=="Leave")
       { 
           temp2+="님이 나갔습니다.";
       } 
        answer.push_back(temp2); 
    }
    
    return answer;
 }
