#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    for(int i = n - 1; i >= 1; i--){
        for(int j = 0; j < i; j++){
            triangle[i][j] > triangle[i][j+1]
                ? triangle[i-1][j] += triangle[i][j]
                : triangle[i-1][j] += triangle[i][j+1];
        }
    }
    return triangle[0][0];
}
