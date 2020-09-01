#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
vector<vector<int> > idxComb;
vector<vector<int> > allCases;
vector<bool> visited;
int n,m;

bool isSame(vector<int>& a, vector<int>& b) {
    if(a.size() != b.size()) return false;
    else {
        for(int i=0; i<a.size(); i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
}

bool isContained(string user, string banned) {
    if(user.length() != banned.length()) {
        return false;
    }
    else {
        for(int i=0; i<user.length(); i++) {
            if(banned[i] != '*') {
                if(user[i] != banned[i]) {
                    return false;
                }
            }
        }
        return true;
    }
}

void countCases(int banned, vector<int>& buffer) {
    if(banned == m) {
        allCases.push_back(buffer);
        return;
    }
    else {
        for(int i=0; i<idxComb[banned].size(); i++) {
            int selected = idxComb[banned][i];
            if(!visited[selected]) {
                buffer.push_back(selected);
                visited[selected] = true;
                countCases(banned+1, buffer);
                visited[selected] = false;
                buffer.pop_back();
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    n=user_id.size(), m=banned_id.size();
    visited.assign(n, false);

    for(int i=0; i<m; i++) {
        vector<int> tmp;
        for(int j=0; j<n; j++) {
            if(isContained(user_id[j], banned_id[i])) {
                tmp.push_back(j);
            }
        }
        idxComb.push_back(tmp);
    }

    vector<int> buf;
    countCases(0, buf);

    int caseNum = allCases.size();
    answer = caseNum;
    for(int i=0; i<caseNum; i++) {
        sort(allCases[i].begin(), allCases[i].end());
    }

    vector<bool> check = vector<bool>(caseNum, 0);
    for(int i=0; i<caseNum; i++) {
        if(check[i]) continue;
        int cnt = 1;   
        check[i] = 1;
        for(int j=i+1; j<caseNum; j++) {
            if(check[j]) continue;
            if(isSame(allCases[i], allCases[j])) {
                cnt++;
                check[j] = 1;
            }
        }
        answer -= (cnt-1);
    }

    return answer;
}