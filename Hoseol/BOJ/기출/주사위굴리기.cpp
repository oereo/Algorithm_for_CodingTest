#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Map[20][20];
int N, M, x, y, k;
int D[1001][6];
int dice2[4][6] = { {3,1,0,5,4,2},{2,1,5,0,4,3},{4,0,2,3,5,1},{1,5,2,3,0,4} };
int dice[6];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int cnt = 0;
void rotateDice(int dir) {
	//east
	if (dir == 1) {
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	//west
	else if (dir == 2) {
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
	//north
	else if (dir == 3) {
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	//south
	else {
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}
}


void movDice(int a, int b, int move)
{
	if (a + dir[move][0] >= 0 && a + dir[move][0] < N&&b + dir[move][1] >= 0 && b + dir[move][1] < M)
	{
		for (int i = 0; i < 6; i++)
		{
			D[cnt][i] = D[cnt - 1][dice2[move][i]];
		}
		rotateDice(move + 1);
		int newA = a + dir[move][0]; int newB = b + dir[move][1];
		if (Map[newA][newB] != 0)
		{
			D[cnt][5] = Map[newA][newB];
			Map[newA][newB] = 0;
		}
		else
		{
			Map[newA][newB] = D[cnt][5];
		}
		//cout << D[cnt][0] << "\n";
		cout << dice[0] << "\n";
		x = newA; y = newB;

	}

}


int main()
{
	cin >> N >> M >> x >> y >> k;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	int move;
	for (int i = 0; i < k; i++)
	{
		cin >> move;
		cnt++;
		movDice(x, y, move - 1);
	}
}