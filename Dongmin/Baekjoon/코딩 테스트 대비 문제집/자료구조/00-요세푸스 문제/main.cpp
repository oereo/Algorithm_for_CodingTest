#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> answer;

    int currentIdx = 0;
    int currentSize = N;
    vector<bool> checked(N, false);
    while (currentSize > 0) {
        int move = (K-1) % currentSize;
        for (int i = 0; i < move; ) {
            currentIdx = ((currentIdx + 1) % N);
            if (checked[currentIdx]) continue;
            i++;
        }

        checked[currentIdx] = true;
        answer.push_back(currentIdx + 1);
        currentSize--;

        if (currentSize == 0) break;
        while (checked[currentIdx]) currentIdx = ((currentIdx + 1) % N);
    }

    string buf = "";
    buf += "<";
    for (int el : answer) {
        buf += ( to_string(el) + ", ");
    }
    buf.pop_back(); buf.pop_back();
    buf += ">";

    cout << buf << endl;

    return 0;
}