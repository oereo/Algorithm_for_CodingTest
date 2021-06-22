#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int* solutions = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> solutions[i];
    }
    
    sort(solutions, solutions + N);
    int mleft = 0, mright = N-1;
    int left = 0, right = N-1;
    int minimum = 0x7fffffff;

    while (left < right) {
        int sum = solutions[left] + solutions[right];

        if (abs(sum) < minimum) {
            minimum = abs(sum);
            mleft = left;
            mright = right;
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << solutions[mleft] << " " << solutions[mright] << endl;
    delete[] solutions;
    return 0;
}