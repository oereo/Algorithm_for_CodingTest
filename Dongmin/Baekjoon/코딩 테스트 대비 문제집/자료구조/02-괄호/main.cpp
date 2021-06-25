#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        bool flag = false;
        int num = 0;
        string expression;
        cin >> expression;

        size_t len = expression.length();
        for (int i = 0; i < len; i++) {
            char p = expression.at(i);
            if (p == '(') num++;
            else if (p == ')') {
                if (num == 0) {
                    cout << "NO\n";
                    flag = true;
                    break;
                }
                num--;
            }
        }

        if (flag) {
            flag = false;
            continue;
        }
        if (num > 0) {
            cout << "NO\n";
            num = 0;
            continue;
        }
        
        cout << "YES\n";
    }
    
    return 0;
}