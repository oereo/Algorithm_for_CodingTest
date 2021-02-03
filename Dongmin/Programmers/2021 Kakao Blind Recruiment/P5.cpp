#include <string>
#include <iostream>
#include <cstring>
#include <vector>

/**
 * [연속적인 값의 연산]
 * 선형적으로 탐색하며 직전의 인덱스를 여러번 참조하여
 * 원하는 데이터 형태로 변환할 수 있음
 **/

using namespace std;

struct Time {
    int h,m,s;
    Time() {
        h=0; m=0; s=0;
    }
    Time(int h, int m, int s) {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    Time(string time) {
        size_t prev=0, cur;
        for (int i=0; i<2; i++) {
            cur = time.find(":");
            string substring = time.substr(prev, cur - prev);
            prev = cur + 1;
            cur = time.find(":", prev);

            if (i==0) this->h = stoi(substring);
            else if (i==1) this->m = stoi(substring);
        }   

        prev = cur + 1;
        cur = time.find(":", prev);
        this->s = stoi(time.substr(prev, cur-prev));
    }

    int toSec() {
        return h*3600 + m*60 + s;
    }
    static Time secToTime(int sec) {
        int h,m,s;
        h = (sec)/3600;
        sec = (sec)%3600;
        m = (sec)/60;
        s = (sec)%60;
        return Time(h,m,s);
    }    

    Time operator+(Time a) {
        
        int tot_sec = toSec() + a.toSec();
        return secToTime(tot_sec);
    }
    Time operator+(int sec) {
        Time t = Time(h,m,s);
        return t + secToTime(sec);

    }

    Time operator-(Time a) {
        int tot_sec = toSec() - a.toSec();
        return secToTime(tot_sec);
    }
    string toString() {
        string ret = "";
        ret += (h/10 + '0'); ret += (h%10 + '0'); ret += ":";
        ret += (m/10 + '0'); ret += (m%10 + '0'); ret += ":";
        ret += (s/10 + '0'); ret += (s%10 + '0');
        return ret;
    }
    bool operator>=(Time a) {
        return this->toSec() >= a.toSec();
    }
    bool operator<=(Time a) {
        return this->toSec() <= a.toSec();
    }
    bool operator>(Time a) {return this->toSec()>a.toSec();}
    bool operator<(Time a) {return this->toSec()<a.toSec();}
};

struct Log {
    Time start, end;
    Log(string start, string end) {
        this->start = Time(start);
        this->end = Time(end);
    }

    bool isInLog(Time moment) {
        return start.toSec() <= moment.toSec() && moment.toSec() <= end.toSec(); 
    }
    int getOverlappedTime(Time start, Time end) {
        if (this->end < start) return 0;
        else if (end < this->start) return 0;
        else if (this->start <= start && this->end >= end) {
            return (end-start).toSec();
        }
        else if (this->start >= start && this->end <= end) {
            return (this->end - this->start).toSec();
        }
        else if (this->start <= start && this->end < end) {
            return (this->end - start).toSec();
        }
        else if (this->start >= start && this->end > end) {
            return (end - this->start).toSec();
        }
        return 0;
    }

};

void parseLog(string log, string& start, string& end) {
    size_t prev=0, cur;
    cur = log.find("-");
    start = log.substr(prev, cur - prev);
    prev = cur + 1;
    cur = log.find("-", prev); 
    end = log.substr(prev, cur-prev);
}


string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int n = logs.size();

    vector<Log> log;
    for (int i=0; i<n; i++) {
        string s, e;
        parseLog(logs[i], s, e);
        log.push_back(Log(s,e));
    }

    Time play = Time(play_time);
    Time adv = Time(adv_time);
    int end_sec = (play - adv).toSec();

    long long total_times[360000];
    memset(total_times, 0, sizeof(total_times));
    
    for (int i=0; i<n; i++) {
        Log l = log[i];
        total_times[l.start.toSec()] = total_times[l.start.toSec()] + 1;
        total_times[l.end.toSec()] = total_times[l.end.toSec()] - 1;
    }

    for (int t=1; t<play.toSec(); t++) {
        total_times[t] = total_times[t] + total_times[t-1];
    }
    for (int t=1; t<play.toSec(); t++) {
        total_times[t] = total_times[t] + total_times[t-1];
    }

    int max_time=0;
    long long max_time_acc = 0;
    for (int t=adv.toSec()-1; t<play.toSec(); t++) {
        if (t >= adv.toSec()) {
            if(max_time_acc < total_times[t] - total_times[t-adv.toSec()] ) {
                max_time_acc = total_times[t] - total_times[t-adv.toSec()];
                max_time = t-adv.toSec() +1;
            }
            
        }
        else {
            if(max_time_acc < total_times[t] ) {
                max_time_acc = total_times[t];
                max_time = t-adv.toSec() +1;
            }
        }  
    }

    Time max_time_format = Time::secToTime(max_time);
    answer = max_time_format.toString();
    return answer;
}