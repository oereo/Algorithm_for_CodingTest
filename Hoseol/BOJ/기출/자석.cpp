#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int mag[4][2][8];
int rotOnce[4];
void Rotate(int M, int dir)
{
		rotOnce[M - 1] = 1;
		int mov1 = M - 1;
		int mov2 = M + 1;
		if (mov1 >= 1 && rotOnce[mov1 - 1] == 0 && mag[M - 1][0][6]!=mag[mov1-1][0][2])
		{
			Rotate(mov1, dir*-1);
		}
		if (mov2 <= 4 && rotOnce[mov2 - 1] == 0 && mag[M - 1][0][2] != mag[mov2 - 1][0][6])
		{
			Rotate(mov2, dir*-1);
		}




		for (int i = 0; i < 8; i++)
		{
			int j = i + dir; 
			if (j == 8) { j = 0; }
			else if (j == -1) { j = 7;}
			mag[M - 1][1][j] = mag[M - 1][0][i];
		}
		for (int i = 0; i < 8; i++)
		{
			mag[M - 1][0][i] = mag[M - 1][1][i];
		}
		
}



int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(mag, 0, sizeof(mag));
		int K;
		cin >> K;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> mag[i][0][j];
			}
		}
		for (int i = 0; i < K; i++)
		{
			memset(rotOnce, 0, sizeof(rotOnce));
			int M, dir;
			cin >> M >> dir;
			Rotate(M, dir);
			
		}
		int ans=0;
		for (int i = 0; i < 4; i++)
		{
			if (mag[i][0][0] == 1)
			{
				ans += pow(2, i);
			}

		}
		cout << "#"<<test_case<<" "<<ans<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}