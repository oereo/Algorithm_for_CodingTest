#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> T;
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int len =timetable.size();
    for(int i=0;i<len;i++)
    {
        int time=0;
        string temp=timetable[i].substr(0,2);
        time+=(atoi(temp.c_str())*60);
        temp=timetable[i].substr(3,5);
        time+=atoi(temp.c_str());
        T.push_back(time);
    }
    sort(T.begin(),T.end());
    int bus_end=540+(n-1)*t; 
    int bus_num=0; int ans;
    for(int bus_time=540;bus_time<=bus_end-t;bus_time+=t)
    {
        int end=0; int how_many=0; bus_num++;
            for(int i=0;i<T.size();i++)
            {
               if(T[end]<=bus_time)
               {  
                  if(how_many==m){break;} 
                  end++; 
                  how_many++; 
               }
                else{break;}
            }
            cout<<bus_time<<","<<end<<endl;
            T.erase(T.begin(),T.begin()+end); 
    }
    if(T.size()>=m){
    ans=T[m-1]-1;}
    else{ans=T[T.size()-1]; ans=max(bus_end,ans);}
    ans=min(ans,bus_end);
    string s=""; string b="";
    if((ans/60)<10){s+="0";}
    s+=to_string(ans/60);
    if(ans%60<10){b+="0";}
    b+=to_string(ans%60);
    answer+=s;
    answer+=":";
    answer+=b;
    return answer;
}