#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;
    
    for(int i = 0; i < phone_book.size(); i++) {
        int length = phone_book[i].size();
        for(int j=1;j<length;j++)
        {
            if(hash_map[phone_book[i].substr(0,j)]==1)
            {answer = false;}
        }
    }
    return answer;
}