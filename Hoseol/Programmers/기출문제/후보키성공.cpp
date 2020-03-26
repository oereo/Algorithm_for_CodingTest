#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
int len1; int len2;
int answer = 0;
vector<vector<string>> relations;
vector<vector<int>> ans;
int visited[10000];
void check(vector<int> comb)
{
    int length=comb.size(); //ex 0,1,2
    vector<string> comp_arr; //비교용어레이
    for(int i=0;i<len1;i++) //명수 각각의인원에대한 후보키조합하기
    {
        string temp="";
        for(int j=0;j<length;j++)
        {
            temp+=relations[i][comb[j]]; //각각사람의 0,1,2 특성 조합하고 삽입
        }
        comp_arr.push_back(temp);
    }
    sort(comp_arr.begin(),comp_arr.end());
    comp_arr.erase(unique(comp_arr.begin(),comp_arr.end()),comp_arr.end());
    if(comp_arr.size()==len1)
    {
        //answer++;
       ans.push_back(comb);
    }
}
void combi_num(int size, int length)// length :속성이몇개인가 ,size:조합길이
{
    vector<int> num0;
    vector<int> num;
    for(int i=0;i<length;i++)
    {
        num.push_back(i);
    }
    for(int i=0;i<length-size;i++)
    {
        num0.push_back(0);
    }
    for(int i=0;i<size;i++)
    {
        num0.push_back(1);
    }
    sort(num.begin(),num.end());
    sort(num0.begin(),num0.end());
    do{
       vector<int> temp;
       for(int i=0;i<length;i++)
       {
        if(num0[i]==1)
        {
        // cout<<num[i];
         temp.push_back(num[i]);
        }
       }
       check(temp);
      // cout<<endl; 
    }while(next_permutation(num0.begin(),num0.end()));
    

}
int solution(vector<vector<string>> relation) {
    relations=relation;
    len1 =relation.size();   //모두몇명인가
    len2=relation[0].size(); //한명의신상정보
    sort(relations.begin(),relations.end());
   for(int i=1;i<=len2;i++)
   {
        combi_num(i,len2);
   }
 sort(ans.begin(),ans.end());
 for(int i=0;i<ans.size();i++)
   {  int mpt=ans[i].size();
       for(int j=0;j<ans.size();j++)
       {
           if(i==j){continue;}
       int ptr1=0;  int ptr2=0;    
       int mpt2=ans[j].size();
        while(1)
        {   
            if(ptr1==mpt){visited[j]=-1;break;}
            if(ptr2==mpt2){break;}
            if(ans[i][ptr1]==ans[j][ptr2])  
            {
                ptr1++;ptr2=0;
            }
            else{
               ptr2++; 
            }
       }
     
   }
   }
     for(int i=0;i<ans.size();i++)
     {
         //cout<<visited[i]<<":";
         // for(int j=0;j<ans[i].size();j++)
         // {
         //    cout<<ans[i][j]<<" ";
         // }cout<<endl;
         if(visited[i]==0)
         {
            answer++;
         }
     }

    return answer;
}