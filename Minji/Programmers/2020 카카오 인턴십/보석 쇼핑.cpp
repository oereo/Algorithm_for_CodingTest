#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
    // 보석 종류 개수 구하기
    int len = gems.size();
    unordered_set<string> gem_set;
    for (int i = 0; i < len; i++)
        gem_set.insert(gems[i]);
    int total = gem_set.size();

    // 가장 짧은 구간 구하기
    int cnt = 0;
    int MIN_len;
    int MIN;
    string MIN_gem;
    vector<int> answer(2);
    unordered_map<string, int> dic;
    for (int i = 0; i < len; i++) {
        MIN = i + 1;
        if (dic[gems[i]] == 0) { // 새로운 보석 종류 발견 시
            cnt++;
            dic[gems[i]] = i + 1;
            if (cnt == total) {
                for (auto d : dic) {
                    if (MIN > d.second) {
                        MIN = d.second;
                        MIN_gem = d.first;
                    }
                }
                answer[0] = MIN;
                answer[1] = i + 1;
                MIN_len = i + 1 - MIN;
            }
            continue;
        }

        dic[gems[i]] = i + 1;
        if (cnt == total && MIN_gem == gems[i]) { // 최솟값 인덱스 변경 시
            for (auto d : dic) {
                if (MIN > d.second) {
                    MIN = d.second;
                    MIN_gem = d.first;
                }
            }
            if (MIN_len > i + 1 - MIN) {
                answer[0] = MIN;
                answer[1] = i + 1;
                MIN_len = i + 1 - MIN;
            }
        }
    }

    return answer;
}