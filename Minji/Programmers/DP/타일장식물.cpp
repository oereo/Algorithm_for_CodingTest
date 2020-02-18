#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int N) {
    
    vector<long long> tile;
    tile.push_back(1);
    tile.push_back(1);
    while(tile.size() != N){
        long long a = tile[tile.size() - 1] + tile[tile.size() - 2]; 
        tile.push_back(a);
    }
    long long ans = 4;
    for(int i = 1; i < N; i++)
        ans = ans + tile[i] * 2;
    return ans;
    
}
