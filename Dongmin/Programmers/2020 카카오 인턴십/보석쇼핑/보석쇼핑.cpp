#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int N, M;
int istart=0, iend=0;
int minLen;
unordered_map<string, int> umap;
unordered_map<string, bool> checked;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.assign(2,0);
    M = gems.size();

    for(int i=0; i<M; i++) {
        if(!umap.count(gems[i])) {
            umap[gems[i]] = 0;
            checked[gems[i]] = 0;
        }
    }
    N = umap.size();

    if(umap.size() == 1) {
        answer[0] = 1;
        answer[1] = 1;
    }
    else if(umap.size() == M) {
        answer[0] = 1;
        answer[1] = N;
    }
    else {
        bool allContained = false;
        int containedNum = 0;
        for(; !allContained; iend++) {
            if(!checked[gems[iend]]) {
                checked[gems[iend]] = 1;
                containedNum += 1;
            }
            umap[gems[iend]] += 1;

            if(containedNum == N) {
                allContained = true;
                minLen = iend-istart+1;
                answer[0] = istart+1;
                answer[1] = iend+1;
                iend-=1;
            }
        }

        while(!(!allContained && iend==M)) {
            if(allContained) {
                istart += 1;
                umap[gems[istart-1]] -= 1;
                if(umap[gems[istart-1]] == 0) {
                    containedNum -= 1;
                    allContained = false;
                }
                else {
                    if(minLen > iend-istart+1) {
                        minLen = iend-istart+1;
                        answer[0] = istart+1;
                        answer[1] = iend+1;
                    }
                }
            }
            else {
                iend += 1;
                if(iend == M) break;
                umap[gems[iend]] += 1;
                if(umap[gems[iend]] == 1) {
                    containedNum += 1;
                    if(containedNum == N) {
                        allContained = true;
                    }
                }

                if(allContained) {
                    if(minLen > iend-istart+1) {
                        minLen = iend-istart+1;
                        answer[0] = istart+1;
                        answer[1] = iend+1;
                    }
                }
            }
        }
    }
    return answer;
}