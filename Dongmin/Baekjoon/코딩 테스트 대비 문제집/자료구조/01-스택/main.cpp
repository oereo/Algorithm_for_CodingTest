#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> stack;
    int N;
    cin >> N;

    string command;
    for (int i = 0; i < N; i++) {
        cin >> command;
        
        if (command == "push") {
            int element;
            cin >> element;
            stack.push_back(element);
        } else if (command == "top") {
            if (!stack.empty()) {
                cout << stack.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if (command == "size") {
            cout << stack.size() << "\n";
        } else if (command == "empty") {
            cout << stack.empty() << "\n";
        } else if (command == "pop") {
            if (!stack.empty()) {
                cout << stack.back() << "\n";
                stack.pop_back();
            } else {
                cout << -1 << "\n";
            }
        }
    }
    

    return 0;
}