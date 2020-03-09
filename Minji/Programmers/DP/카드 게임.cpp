#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer1 = 0;
    int answer2 = 0;
    int len = left.size();
    
    // answer1 : 앞에서부터
    int i = 0;
    int j = 0;
    while(i != len && j != len){
        if(left[i] > right[j]){
            answer1 += right[j];
            j++;
            continue;
        }
        if(*max_element(left.begin()+i+1, left.end()) > right[j]){
            i++;
        }
        else{
            i++;
            j++;
        }
    }
    
    // answer2 : 뒤에서부터
    i = len - 1;
    j = len - 1;
    while(i != -1 && j != -1){
        cout << left[i] << " " << right[j] << endl;
        if(left[i] > right[j]){
            answer2 += right[j];
            j--;
            continue;
        }
        if(*max_element(left.begin(), left.begin() + i) > right[j]){
            i--;
        }
        else{
            i--;
            j--;
        }
    }
    if(answer1 > answer2)
        return answer1;
    return answer2;
}