#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> copy_words;
int n, m;

int BFS(string begin, string target, vector<int> visited){
    vector<string> start;
    vector<string> temp;
    start.push_back(begin);
    int count = 1;
    while(1){
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                int equal = 0;
                for(int j = 0; j < m; j++){
                    if(start.front()[j] == copy_words[i][j])
                        equal++;
                }
                if(equal == m - 1){
                    visited[i] = 1;
                    if(copy_words[i] == target)
                        return count;
                    else
                        temp.push_back(copy_words[i]);
                }
            }
        }
        start.erase(start.begin());
        if(start.empty()){
            count++;
            start = temp;
            temp.clear();
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    n = words.size();
    m = begin.size();
    copy_words = words;
    vector<int> visited;
    visited.assign(n,0);
    int answer = BFS(begin, target, visited);
    return answer;
}
