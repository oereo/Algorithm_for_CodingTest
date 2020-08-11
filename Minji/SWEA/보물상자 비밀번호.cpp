#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
using namespace std;

int DEC(string n) {
    int len = n.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
        if (n[i] >= '0' && n[i] <= '9')
            result += (n[i] - '0') * pow(16, len - i - 1);
        else
            result += (n[i] - 'A' + 10) * pow(16, len - i - 1);
    }
    return result;
}

int main(int argc, char** argv) {
    int test_case;
    int T, N, K, M;
    string n;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> K;
        M = N / 4;
        vector<char> num(N);
        vector<int> answer;

        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 4; j++) {
                n = "";
                for (int k = 0; k < M; k++) {
                    n += num[((j * M) + k + i) % N];
                }
                answer.push_back(DEC(n));
            }
        }
        sort(answer.begin(), answer.end(), greater<int>());
        unique(answer.begin(), answer.end());

        cout << "#" << test_case << " " << answer[K - 1] << endl;
    }
    return 0;
}