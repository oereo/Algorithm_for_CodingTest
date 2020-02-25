#include <iostream>
#include <vector>
using namespace std;
int n;
int m;
int ans=-1;
int map[100][100];
int visited[100];
void DFS(int cnt,int a, int b)
{
	visited[a] = 1;
	if (b == a)
	{
		ans= cnt;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0 && map[a][i] == 1)
		{
			DFS(cnt + 1, i, b);
		}
	}

	
}

int main()
{
	cin >> n;
	int A, B;
	cin >> A >> B;
	cin >> m;
	int q, w;
	for (int i = 0; i < m; i++)
	{
		cin >> q >> w;
		map[q - 1][w - 1] = 1;
		map[w - 1][q - 1] = 1;

	}
	DFS(0, A-1, B-1);
	cout << ans;

}

