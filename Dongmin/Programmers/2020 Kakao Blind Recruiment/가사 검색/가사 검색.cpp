#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
typedef struct Node {
    int leaf_num;
    unordered_map<char, Node*> link;
} Node;
typedef map<int, unordered_map<char, Node*> > Tree;
Tree tree, reverse_tree;
vector<int> solution(vector<string> words, vector<string> queries) {
    int n = words.size();
    vector<int> answer;
    vector<string> reverse_words;
    for(auto word:words) {
        reverse(word.begin(), word.end());
        reverse_words.push_back(word);
    }

    for(string word:words) {
        int len = word.length();
        
        if(!tree.count(len)) {
            tree[len] = unordered_map<char, Node*>();   
        }

        unordered_map<char, Node*> *subtree = &tree[len];
        for(int i=0; i<len; i++) {
            if(!subtree->count(word[i])) {
                pair<char, Node*> node (word[i], new Node{1, unordered_map<char, Node*>()});
                subtree->insert(node);
            }
            else {
                subtree->find(word[i])->second->leaf_num += 1;
            }
            subtree = &subtree->find(word[i])->second->link;
        }
    }

    for(string word:reverse_words) {
        int len = word.length();
        if(!reverse_tree.count(len)) {
            reverse_tree[len] = unordered_map<char, Node*>();   
        }

        unordered_map<char, Node*> *subtree = &reverse_tree[len];
        for(int i=0; i<len; i++) {
            if(!subtree->count(word[i])) {
                pair<char, Node*> node (word[i], new Node{1, unordered_map<char, Node*>()});
                subtree->insert(node);
            }
            else {
                subtree->find(word[i])->second->leaf_num += 1;
            }
            subtree = &subtree->find(word[i])->second->link;
        }
    }

    for(string query: queries) {
        int len = query.length();
        unordered_map<char, Node*> subtree;
        Node* node;
        bool not_exist = false;

        if(!tree.count(len)) {
            answer.push_back(0);
            continue;
        }
        else {
            subtree = query[0]!='?' ? tree[len]:reverse_tree[len];
        }

        if(query[0] != '?') {
            string prefix = query.substr(0, query.find_first_of('?'));
            for(char ch: prefix) {
                if(!subtree.count(ch)) {
                    answer.push_back(0);
                    not_exist = true;
                    break;
                }
                node = subtree[ch];
                subtree = subtree[ch]->link;
            }
        }
        else {
            if(query.back() == '?') {
                int num = 0;
                for(auto it: subtree) {
                    num += it.second->leaf_num;
                }
                answer.push_back(num);
                continue;
            }

            string suffix = query.substr(query.find_first_not_of('?'));
            reverse(suffix.begin(), suffix.end());
            for(char ch: suffix) {
                if(!subtree.count(ch)) {
                    answer.push_back(0);
                    not_exist = true;
                    break;
                }
                node = subtree[ch];
                subtree = subtree[ch]->link;
            }
        }

        if(!not_exist) {
            answer.push_back(node->leaf_num);
        }
    }

    return answer;
}