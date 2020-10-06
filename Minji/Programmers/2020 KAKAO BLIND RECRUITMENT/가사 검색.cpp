#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie{
    Trie* next[26];
    int cnt;
    
    Trie() : cnt(1){
        memset(next, 0, sizeof(next));
    }
    
    void insert(const char* key){
        if (*key == '\0')
            return;
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL)
                next[curr] = new Trie();
            else next[curr]->cnt++;
            next[curr]->insert(key + 1);
        }
    }
    
    int find(const char* key){
        int curr = *key - 'a';
        if(*key == '?'){
            int tmp = 0;
            for(int i = 0; i < 26; i++){
                if(next[i] != NULL) tmp += next[i]->cnt;
            }
            return tmp;
        }
        if(next[curr] == NULL) return 0;
        if(*(key+1) == '?') return next[curr]->cnt;
        return next[curr]->find(key+1);
    }
        
};

Trie *root[10001];
Trie *reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    int wSize = words.size();
    int qSize = queries.size();
    vector<int> answer(qSize,0);
    
    for(auto &w : words){
        int size = w.size();
        
        const char *c = w.c_str();
        if(root[size] == NULL) root[size] = new Trie();
        root[size]->insert(c);
        
        string reversed = w;
        reverse(reversed.begin(),reversed.end());
        
        const char *r = reversed.c_str();
        if(reroot[size] == NULL) reroot[size] = new Trie();
        reroot[size]->insert(r);
    }
    
    int idx = 0;
    for(auto & q : queries){
        int size = q.size();
        if(q[size-1] == '?'){
            const char *c = q.c_str();
            if(root[size] == NULL) {idx++; continue;}
            else answer[idx] = root[size]->find(c);
        }
        else{
            string re = q;
            reverse(re.begin(),re.end());
            const char *r = re.c_str();
            
            if(reroot[size] == NULL){idx++; continue;}
            else answer[idx] = reroot[size]->find(r);
        }
        idx++;
    }
    return answer;
}

// 출처 : https://velog.io/@seovalue/%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B0%80%EC%82%AC%EA%B2%80%EC%83%89-C#