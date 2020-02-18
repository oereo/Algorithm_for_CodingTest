#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int checked[100];
int solution(string name) {
    int answer = 0;
    int len=name.size();
    int key=0;
    for(int i=0;i<len;i++)
    {
        answer+=min((int)name[i]-65,91-(int)name[i]);
        if((int)name[i]-65!=0)
        {
            checked[i]=1;   
            key++;
        }
        
    }
    int right=0; int left=0; int po=0; 
    while(1)
    {
        int right_len=0; int left_len=0;
     
        int poR=po;
        if(checked[po]==1)
        {
            key--;
            checked[po]=0;
        }
          if(key==0)
        {
            break;
        }
        while(1){
        right_len++;
        if(poR+1==len) {right=0;}
        else {right=poR+1;}
         if(checked[right]==1)
         {
           break; 
         }
        else
        {
            poR++;
            if(poR==len)
            {
                poR=0;
            }
        }
        }
        int poL=po;
        while(1){
        left_len++;
        if(poL-1==-1) {left=len-1;}
        else {left=poL-1;}
         if(checked[left]==1)
         {
           break; 
         }
        else
        {
            poL--;
            if(poL==-1)
            {
                poL=len-1;
            }
        }
        }
     if(right_len<=left_len)
     {
        po=right;
        answer+=right_len; 
          
     }
    else
    {
       po=left; 
       answer+=left_len; 
     
    }  
        
        
    }
    
    
    
    return answer;
}