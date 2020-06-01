#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int M, N;

bool check(vector<vector<int>> temp)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (temp[i + M - 1][j + M - 1] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    // 보드 만들기
    M = key.size();
    N = lock.size();
    int len = (M - 1) * 2 + N;
    vector<vector<int>> board(len, vector<int>(len));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i + M - 1][j + M - 1] = lock[i][j];
        }
    }

    // Key 맞춰보기
    for (int dir = 0; dir < 4; dir++)
    {
        for (int a = 0; a <= len - M; a++)
        {
            for (int b = 0; b <= len - M; b++)
            {
                vector<vector<int>> temp = board;
                for (int i = a; i < a + M; i++)
                {
                    for (int j = b; j < b + M; j++)
                    {
                        temp[i][j] += key[i - a][j - b];
                    }
                }
                if (check(temp))
                    return true;
            }
        }

        // Key 시계방향으로 90도 회전
        vector<vector<int>> temp_key(M, vector<int>(M));
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                temp_key[i][j] = key[M - j - 1][i];
            }
        }
        key = temp_key;
    }
    return false;
}