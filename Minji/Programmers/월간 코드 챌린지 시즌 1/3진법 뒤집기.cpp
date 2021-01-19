#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<int> result;
    int answer = 0;
    int len = 0;
    while (n != 0) {
        result.push_back(n % 3);
        n /= 3;
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        answer += result[i] * pow(3, len - i - 1);
    }
    return answer;
}