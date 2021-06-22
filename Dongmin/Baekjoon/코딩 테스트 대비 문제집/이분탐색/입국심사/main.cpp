#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M;
    int* times = new int[N];

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }
    
    unsigned long long maxTime = *max_element(times, times + N);
    unsigned long long right = maxTime * M;
    unsigned long long left = 0;

    unsigned long long ans = 0xffffffffffffffff;
    while (left <= right) {
        unsigned long long mid = (left + right) / 2;
        unsigned long long current = 0;
        for (int i = 0; i < N; i++) {
            current += (mid / times[i]);
        }
        
        if (current >= M) {
            ans = min(mid, ans);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    delete[] times;
    return 0;
}