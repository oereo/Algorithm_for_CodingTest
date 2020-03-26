#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
int visited[8];
int len1; int len2;
int answer = 0;
vector<vector<string>> relations;
void check(vector<int> comb)
{
    int length=comb.size(); //ex 0,1,2
    vector<string> comp_arr; //비교용어레이
    for(int j=0;j<length;j++)
    {
        if(visited[comb[j]]!=0&&length>visited[comb[j]])
        {
            return;
        }
    }
   
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
        answer++;
        for(int j=0;j<len1;j++)
        {
           cout<<comp_arr[j]<<endl;
        }
        cout<<endl;
        for(int j=0;j<length;j++)
        {
            visited[comb[j]]=length;
        }
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

    return answer;
}