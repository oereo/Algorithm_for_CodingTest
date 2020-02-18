#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    vector< unordered_set<int> > cal(8);
    int nn = 0;
    
    for(int i = 0; i < 8; i++){
        nn = nn * 10 + 1;
        cal[i].insert(nn * N);
        if(nn*N == number)
            return i+1;
    }
    
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                if(j + k + 1 != i)
                    continue;
                for(int a : cal[j]){
                    for(int b : cal[k]){
                        cal[i].insert(a + b);
                        if(a - b > 0)
                            cal[i].insert(a - b);
                        cal[i].insert(a * b);
                        if(a / b > 0)
                            cal[i].insert(a / b);
                    }
                }
            }
        }
        if(cal[i].count(number) == 1)
            return i+1;
    }
    return -1;
}
