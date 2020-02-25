#include <iostream>
using namespace std;
int map[100][100];
int F[100][100];
int MAX = 100000;

void floyd(int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (F[i][k] && F[k][j] )
				{
					F[i][j] =1;
				}
				
				
			}
		}
	}

}



int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			F[i][j] = map[i][j];
		}
	}
	floyd(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}

}

