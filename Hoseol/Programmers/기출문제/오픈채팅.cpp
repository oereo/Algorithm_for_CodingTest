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
         else{ptr=7;} //change 일때는 7번째 인덱스부터 탐색
        string temp;
        while(1) //temp에는 아이디가 들어간다
        {
          if(record[i][ptr]==' ')
          {ptr++;break;}
          else{ temp+=record[i][ptr]; ptr++;}  
        }
        string temp2; //temp2에는 닉네임이들어간다.
        while(1)
        {
          if(ptr==siz)
          {break;}
          else{ temp2+=record[i][ptr]; ptr++;}  
        }
        M[temp]=temp2;           
      }
     
    }
    
    for(int i=0;i<len;i++)
    {
       if(record[i].substr(0,6)=="Change") //출력은 입장과 나가는것만하면된다.
       {continue;}   
        int siz=record[i].size();
        int ptr=6;
        string temp; //위와마찬가지로 id를 temp에 넣는과정
        while(1)
        {
          if(record[i][ptr]==' '||ptr==siz)
          {ptr++;break;}
          else{temp+=record[i][ptr]; ptr++;}  
        }
       string temp2=M[temp]; //id에맞는 업데이트된 닉네임을 찾아온다
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
