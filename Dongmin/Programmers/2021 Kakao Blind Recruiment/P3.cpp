#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, vector<int> > combs;

// stl sort의 시간복잡도는 nlgn

void dfs(vector<string>& token, string str, int depth, int score) {

    if (depth == token.size()) {
        if (combs.count(str) == 0) {
            combs[str] = vector<int>();
            combs[str].push_back(score);
        }
        else {
            combs[str].push_back(score);
        }
    }
    else {
        dfs(token, str+token[depth], depth+1, score);
        dfs(token, str+"-", depth+1, score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    // 50000 * 16
    for (int i=0; i<info.size(); i++) {
        string comb = "";
        vector<string> token;

        string str = info[i];
        size_t prev = 0, current;
        current = str.find(' ');

        for (int j=0; j<4; j++) {
            string substring = str.substr(prev, current - prev);
            comb += substring;
            prev = current + 1;
            current = str.find(' ', prev);
            token.push_back(substring);
        }
        
        int score = stoi(str.substr(prev, current-prev));
        dfs(token, "", 0, score);
    }

    for (auto& c: combs ) {
        sort(c.second.begin(), c.second.end());
    }

    for (int i=0; i<query.size(); i++) {
        string query_series = "";
        string str = query[i];
        size_t prev = 0, current;
        current = str.find(' ');

        while (current != string::npos) {
            string substring = str.substr(prev, current - prev);
            prev = current + 1;
            current = str.find(' ', prev);
            if (substring == "and") continue;
            query_series += substring;
        }
        
        int score = stoi(str.substr(prev, current-prev));
        if (combs.count(query_series) == 0) {
            answer.push_back(0);
        }
        else {
            vector<int> scores = combs[query_series];
            size_t idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
            answer.push_back(scores.size() - idx);

        }
    }

    return answer;
}