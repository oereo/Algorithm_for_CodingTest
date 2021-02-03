#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> comb;
struct FreqComb {
    int freq;
    string comb;

    bool operator<(const FreqComb& a) {
        if (freq == a.freq) {
            return comb > a.comb;
        }
        return freq > a.freq;
    }
};


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int o=0; o<orders.size(); o++) {

        string order = orders[o];
        sort(order.begin(), order.end());
        for (int l=0; l<course.size(); l++) {
            int len = course[l];
            if (len > order.size()) break;
            vector<int> temp;
            temp.assign(order.size(), 0);

            for (int i=0; i<len; i++) {
                temp[i] = 1;
            }
            
            do {

                string c = "";
                for (int i=0; i<order.size(); i++) {
                    if (temp[i]==1) {
                        c += order[i];
                    }
                }

                if(comb.count(c) == 0) {
                    comb[c] = 1;
                } else {
                    comb[c] += 1;
                }
            } while(prev_permutation(temp.begin(), temp.end()));

        }
    }

    vector<vector<FreqComb> > fcs;
    fcs.assign(course.back()+1, vector<FreqComb>());

    for(auto c:comb){
        if (c.second >= 2) {
            fcs[c.first.length()].push_back(FreqComb{ c.second, c.first });
        }
    }


    for (int i=0; i<course.size(); i++) {

        int len = course[i];
        sort(fcs[len].begin(), fcs[len].end());
        int max_freq = fcs[len].front().freq;

        for (int j=0; j<fcs[len].size(); j++) {
            if (fcs[len][j].freq != max_freq) break;
            answer.push_back(fcs[len][j].comb);
        }

    }

    sort(answer.begin(), answer.end());
    return answer;
}