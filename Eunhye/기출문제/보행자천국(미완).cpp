#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int city_map[501][501];
int down[501][501]; 
int Right[501][501];
int m, n,res;
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> city_map[i][j];
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (city_map[i][j] == 1)
			{
				Right[i][j+1] = 0;
				down[i+1][j] = 0;
			}
			else if (city_map[i][j] == 2)
			{
				Right[i][j + 1] = Right[i][j];//직진하니깐 전의 값 그대로 오는 것
				down[i + 1][j] = down[i][j];
			}
			else 
			{
				Right[i][j + 1] = down[][] + Right[][];
				down[i+1][j]
			}

		}
	}
	res = res % 20170805;
	cout << res << endl;
}







//int x[4] = { 0, 0, 1, -1 };
//int y[4] = { -1,1,0,0 };
//void BFS(int col,int row) 
//{
//	queue<pair<int, int>> q;
//
//	q.push({ col,row });
//	visit[col][row] = true;
//	int xNow,yNow,xNext,yNext; 
//	while (!q.empty())
//	{
//		yNow = q.front().first;
//		xNow = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			xNext = xNow + x[i];
//			yNext = yNow + y[i];
//				if (!visit[xNext][yNext]&&city_map[xNext][yNext]==0)
//				{
//					q.push({xNext,yNext});
//					visit[xNext][yNext] = true;
//				}
//			
//		}
//
//		}
//}
//int main()
//{
//	
//	cin >> m >> n;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> city_map[i][j];
//		}
//	}
//	BFS(m, n);
//	res = res % 20170805;
//	cout << res << endl;
//	
//}