#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    sort(weight.begin(), weight.end());
    int MAX = 0;
    int len = weight.size();
    for (int i = 0; i < len; i++) {
        if(MAX + 1  > weight[i]) break;
        MAX += weight[i];
    }
    return MAX + 1;
}