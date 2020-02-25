#include <iostream>
using namespace std;
int map[10][10];

int co[10][10];
int visited[10][10];
int temp[10][10];
int answer=-1000;
int N, M;
void cop()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			co[i][j] = map[i][j];
		}
	}
}

void virus(int i ,int j)
{


	visited[i][j] = 1;
	if ((i - 1) >= 0) //위
	{
		if (temp[i - 1][j] == 0&&visited[i-1][j]==0)
		{
			temp[i - 1][j] = 2;
			virus(i - 1, j);
		}

	}
	if ((i + 1) < N) //아래
	{
		if (temp[i + 1][j] == 0 && visited[i + 1][j] == 0)
		{
			temp[i + 1][j] = 2;
			virus(i + 1, j);
		}

	}
	if ((j - 1) >=0 ) //왼쪽
	{
		if (temp[i][j-1] == 0 && visited[i][j-1] == 0)
		{
			temp[i][j-1] = 2;
			virus(i, j-1);
		}

	}
	if ((j + 1) < M) //오른쪽
	{
		if (temp[i][j + 1] == 0 && visited[i][j+1] == 0)
		{
			temp[i][j + 1] = 2;
			virus(i, j + 1);
		}

	}
			

}
int ans()
{
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			
			if (temp[i][j] == 0)
			{
				t++;
			}
			
		}
		
	}
	
return t;

}
void Vclear()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 0;			
		}		
	}
}

void findWall(int cnt)
{
	if (cnt == 3)
	{
	
		Vclear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				//cout << temp[i][j] << " ";
				temp[i][j] = co[i][j];
			}
			//cout << endl;
		}
		//cout << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp[i][j] == 2&&visited[i][j]==0)
				{
					virus(i, j);
					
				}
			}
		}

		
		int k = ans();
		
		if (answer <k)
		{
			answer = k;
		}
		return;


	}
	else {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (co[i][j] == 0)
				{

					co[i][j] = 1;
					findWall(cnt + 1);
					co[i][j] = 0;
				}

			}
		}
	}
}

int main()
{
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				cop();
				co[i][j] = 1;
				findWall(1);
				co[i][j] = 0;

			}

		}
	}

	cout << answer;




	

}

