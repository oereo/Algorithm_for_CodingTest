#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> M; 
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int len1=participant.size();
    int len2=completion.size();
    for(int i=0;i<len2;i++)
    {
        M[completion[i]]+=1;
    }
    for(int i=0;i<len2;i++)
    {
        if(M.find(participant[i])==M.end())
        {
            return participant[i];
        }
        else
        {
            M[participant[i]]-=1;
            if(M[participant[i]]<0)
            {
                return participant[i];
            }
        }
    }
    
    return answer;
}