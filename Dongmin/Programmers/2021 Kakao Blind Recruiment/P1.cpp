#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

bool isValidChar(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c<='z') || c == '-' || c == '_' || c == '.';
}

string solution(string new_id) {
    string answer = "";
    //1
    std::transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    //2
    string banned_char;
    for(char ch: new_id) {
        if(!isValidChar(ch)) {
            banned_char += ch;
        }
    }
    for(auto ch: banned_char) {
        new_id.erase(std::find(new_id.begin(), new_id.end(), ch));
    }
    //3
    typedef struct DotDup {
        int pos;
        int num;
    } DotDup;

    vector<DotDup> dups;
    bool isDot = false;
    int start = 0;
    int num = 1;
    for(int i=0; i<new_id.size(); i++) {
        char ch = new_id[i];
        if(!isDot) {
            if(ch == '.') {
                start = i;
                isDot = true; 
            }
            else isDot = false;
        }
        else {
            if(ch == '.') {
                num += 1;
            }
            else {
                isDot = false;
                dups.push_back({start, num});
                num = 1;
            }
        }
    }
    if(num >= 2) {
        dups.push_back({start, num});
    }

    for(int i=dups.size()-1; i>=0; i--) {
        new_id.erase(dups[i].pos+1, dups[i].num-1);
    }

    //4
    if(new_id.back() == '.') {
        new_id.pop_back();
    }
    if(new_id.front() == '.') {
        new_id.erase(0,1);
    }

    //5
    if(new_id.size() == 0) new_id += 'a';

    //6
    if(new_id.size() >= 16) {
        new_id.erase(new_id.begin()+15, new_id.end());
        if(new_id.back() == '.') new_id.pop_back();
    }
    //7
    if(new_id.size() <= 2) {
        char backch = new_id.back();
        while(new_id.size() != 3) {
            new_id += backch;
        }
    }

    answer = new_id;
    return answer;
}