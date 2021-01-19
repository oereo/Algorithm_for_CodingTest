#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> result(n, vector<int>(n, -1));
    int end = 0;
    for (int i = 1; i <= n; i++) end += i;
    int dir[3][2] = { {1,0},{0,1},{-1,-1} };
    int x = 0, y = 0, cnt = 1, num = 2;
    result[x][y] = 1;
    while (1) {
        for (int i = 0; i < 3; i++) {
            while (1) {
                if (num > end) break;
                x += dir[i][0], y += dir[i][1];
                if (x >= n || y >= n || result[x][y] != -1) {
                    x -= dir[i][0], y -= dir[i][1];
                    break;
                }
                result[x][y] = num++;
            }
            if (num > end) break;
        }
        if (num > end) break;
    }

    vector<int> answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(result[i][j]);
        }
    }
    return answer;
}