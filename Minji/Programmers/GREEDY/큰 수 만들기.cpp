#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int n = number.size();
    while(k != 0){
        for(int i = 0; i < n-1; i++){
            if(number[i] < number[i+1]){
                number.erase(i,1);
                n--;
                k--;
                break;
            }
            if(i == n - 2){
                number.erase(n-1,1);
                n--;
                k--;
            }
        }
    }
    return number;
}
