#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T, N;
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        int MAX = -100000000;
        int MIN = 100000000;
        vector<int> opers;
        vector<int> nums;

        // 입력 받기
        cin >> N;
        for (int i = 0; i < 4; i++)
        {
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                opers.push_back(i);
            }
        }
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            nums.push_back(n);
        }

        // 연산자 조합하기
        do
        {
            int result = nums[0];
            for (int i = 0; i < N - 1; i++)
            {
                switch (opers[i])
                {
                case 0: // +
                    result += nums[i + 1];
                    break;
                case 1: // -
                    result -= nums[i + 1];
                    break;
                case 2: // *
                    result *= nums[i + 1];
                    break;
                case 3: // /
                    result /= nums[i + 1];
                    break;
                }
            }

            if (result > MAX)
                MAX = result;
            if (result < MIN)
                MIN = result;
        } while (next_permutation(opers.begin(), opers.end()));

        cout << "#" << test_case << " " << MAX - MIN << endl;
    }
    return 0;
}