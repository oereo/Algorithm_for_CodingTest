#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    int section_len = arr.size();
    int total_len = section_len;
    int idx = 0;
    while (section_len != 0) {
        for (int a = 0; a < total_len; a += section_len) {
            for (int b = 0; b < total_len; b += section_len) {
                bool check = true;
                int start = arr[a][b];
                if (start == -1) continue;
                for (int i = 0; i < section_len; i++) {
                    for (int j = 0; j < section_len; j++) {
                        if (start != arr[a + i][b + j]) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) break;
                }
                if (check) {
                    answer[start]++;
                    for (int i = 0; i < section_len; i++) {
                        for (int j = 0; j < section_len; j++) {
                            arr[a + i][b + j] = -1;
                        }
                    }
                }
            }
        }

        section_len /= 2;
    }
    return answer;
}