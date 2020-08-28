#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int test_case, i, k, t, c, answer;
    int T, N, M, K, A, B;
    int reception[20][3];
    int repair[20][3];
    int customer[1000];
    queue<int> rec_waiting;
    queue<int> rep_waiting;
    vector<int> a_list;
    vector<int> b_list;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        //입력 받기
        cin >> N >> M >> K >> A >> B;
        memset(reception, 0, sizeof(reception));
        memset(repair, 0, sizeof(repair));
        memset(customer, 0, sizeof(customer));
        a_list.clear();
        b_list.clear();
        for (i = 0; i < N; i++)
        {
            cin >> reception[i][0];
        }
        for (i = 0; i < M; i++)
        {
            cin >> repair[i][0];
        }
        for (i = 0; i < K; i++)
        {
            cin >> customer[i];
        }

        // 접수 및 수리
        t = 0, c = 0;
        while (1)
        {
            // 접수 대기열 추가
            while (1)
            {
                if (c < K && customer[c] == t)
                {
                    rec_waiting.push(++c);
                    continue;
                }
                break;
            }

            // 접수 & 수리 대기열 추가
            for (i = 0; i < N; i++)
            {
                if (reception[i][1] != 0 && reception[i][2] == reception[i][0])
                { // 접수 완료
                    rep_waiting.push(reception[i][1]);
                    reception[i][1] = 0;
                }

                if (!rec_waiting.empty() && reception[i][1] == 0)
                { // 빈 창구
                    reception[i][1] = rec_waiting.front();
                    rec_waiting.pop();
                    reception[i][2] = 0;
                    if (i + 1 == A)
                        a_list.push_back(reception[i][1]);
                }

                if (reception[i][1] != 0)
                    reception[i][2]++;
            }

            // 수리
            for (i = 0; i < M; i++)
            {
                if (repair[i][2] == repair[i][0])
                { // 수리 완료
                    repair[i][1] = 0;
                }

                if (!rep_waiting.empty() && repair[i][1] == 0)
                { // 빈 창구
                    repair[i][1] = rep_waiting.front();
                    rep_waiting.pop();
                    repair[i][2] = 0;
                    if (i + 1 == B)
                        b_list.push_back(repair[i][1]);
                }

                if (repair[i][1] != 0)
                    repair[i][2]++;
            }

            // 종료
            if (c == K && rec_waiting.empty() && rep_waiting.empty())
            {
                bool check = true;
                for (i = 0; i < N; i++)
                {
                    if (reception[i][1] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                    break;
            }

            t++;
        }

        answer = 0;
        sort(a_list.begin(), a_list.end());
        sort(b_list.begin(), b_list.end());
        vector<int> result(a_list.size() + b_list.size());
        set_intersection(a_list.begin(), a_list.end(), b_list.begin(), b_list.end(), result.begin());
        for (int a : result)
            answer += a;
        if (answer == 0)
            answer = -1;

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}