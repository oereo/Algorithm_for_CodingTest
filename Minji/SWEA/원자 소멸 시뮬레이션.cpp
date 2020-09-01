#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct collision
{
    int d;
    int a1;
    int a2;
};

bool cmp(collision a, collision b)
{
    return a.d < b.d;
}

int main(int argc, char **argv)
{
    int test_case, i, j, diff_x, diff_y, answer;
    int T, N;
    int atoms[1000][4];
    vector<collision> collisions;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        memset(atoms, 0, sizeof(atoms));
        collisions.clear();
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < 4; j++)
            {
                cin >> atoms[i][j];
            }
        }

        for (i = 0; i < N; i++)
        {
            if (atoms[i][3] == 0)
                continue;
            diff_x = atoms[i][0];
            diff_y = atoms[i][1];
            for (j = i + 1; j < N; j++)
            {
                diff_x -= atoms[j][0];
                diff_y -= atoms[j][1];
                switch (atoms[i][2])
                {
                case 0:
                    if (diff_y <= 0 && ((diff_x == 0 && atoms[j][2] == 1) || (diff_x == diff_y && atoms[j][2] == 2) || (diff_x == -diff_y && atoms[j][2] == 3)))
                    {
                        collisions.push_back({abs(diff_y) + abs(diff_x), i, j});
                    }
                    break;
                case 1:
                    if (diff_y >= 0 && ((diff_x == 0 && atoms[j][2] == 0) || (diff_x == diff_y && atoms[j][2] == 3) || (diff_x == -diff_y && atoms[j][2] == 2)))
                    {
                        collisions.push_back({abs(diff_y) + abs(diff_x), i, j});
                    }
                    break;
                case 2:
                    if (diff_x >= 0 && ((diff_y == 0 && atoms[j][2] == 3) || (diff_x == diff_y && atoms[j][2] == 0) || (diff_x == -diff_y && atoms[j][2] == 1)))
                    {
                        collisions.push_back({abs(diff_y) + abs(diff_x), i, j});
                    }
                    break;
                case 3:
                    if (diff_x <= 0 && ((diff_y == 0 && atoms[j][2] == 2) || (diff_x == diff_y && atoms[j][2] == 1) || (diff_x == -diff_y && atoms[j][2] == 0)))
                    {
                        collisions.push_back({abs(diff_y) + abs(diff_x), i, j});
                    }
                    break;
                }
                diff_x += atoms[j][0];
                diff_y += atoms[j][1];
            }
        }
        if (collisions.empty())
            answer = 0;
        else
        {
            sort(collisions.begin(), collisions.end(), cmp);
            unordered_set<int> idx;
            int distance = collisions[0].d, first_idx = collisions[0].a1, len = collisions.size();
            answer = atoms[collisions[0].a1][3] + atoms[collisions[0].a2][3];
            idx.insert(collisions[0].a1);
            idx.insert(collisions[0].a2);
            for (i = 1; i < len; i++)
            {
                if (idx.size() == N)
                    break;
                if (distance == collisions[i].d && first_idx == collisions[i].a1)
                {
                    if (idx.count(collisions[i].a2) != 0)
                        continue;
                    answer += atoms[collisions[i].a2][3];
                    idx.insert(collisions[i].a2);
                }
                else
                {
                    if (idx.count(collisions[i].a1) != 0)
                        continue;
                    if (idx.count(collisions[i].a2) != 0)
                        continue;
                    distance = collisions[i].d, first_idx = collisions[i].a1;
                    idx.insert(collisions[i].a1);
                    idx.insert(collisions[i].a2);
                    answer += atoms[collisions[i].a1][3] + atoms[collisions[i].a2][3];
                }
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}