#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<string,vector<vector<int>>> M;
map<string,int> BEST;
vector<string> check;
void build_map(vector<string> genres, vector<int> plays)
{
    int len=genres.size();
    for(int i=0;i<len;i++)
    {
        check.push_back(genres[i]);
        vector<int> temp;
        temp.push_back(plays[i]);
        temp.push_back(i);
        M[genres[i]].push_back(temp);
        BEST[genres[i]]+=plays[i];
    }
}

vector<vector<int>> search(string b)
{
    int len=M[b].size();
    vector<vector<int>> temp;
    for(int i=0;i<len;i++)
    {
        vector<int> t;
        t.push_back(M[b][i][0]);
        t.push_back(-M[b][i][1]);
        temp.push_back(t);
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i][0]<<","<<temp[i][1]<<endl;
    }
    vector<vector<int>> list;
    list.push_back(temp.back());
    temp.pop_back();
    if(temp.size()>0)
    {
         list.push_back(temp.back());
         temp.pop_back();
    }
    return list;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    build_map(genres,plays);
    sort(check.begin(),check.end());
    check.erase(unique(check.begin(),check.end()),check.end());
    int len=genres.size();
    int cnt=M.size();
    int genre_size=check.size();
    while(cnt>0)
    {
    string best="";
    int cmp=-2;
    for(int i=0;i<genre_size;i++)
    {
        if(BEST[check[i]]>cmp)
        {
            cmp=BEST[check[i]];
            best=check[i];
        }
    }
    vector<vector<int>> List=search(best);
    int length=List.size();
        for(int i=0;i<length;i++)
        {
            answer.push_back(-List[i][1]);
        }
        BEST[best]=-2;
        cnt--;
    }
    return answer;
}
