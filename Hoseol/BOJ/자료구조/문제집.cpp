#include <iostream>
#include <vector>
using namespace std;
int ft[32001];
vector<int> num[32001];
int main()
{
	int print;
	int N, M;
	cin >> N>> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b; //4,2
		num[a].push_back(b);
		ft[b]++;
	}
	while (1)
	{ 
		print = -1;
		for (int i = 1; i <= N; i++)
		{
			if (ft[i] == 0)
			{
				print = i;
				break;
			}
		}
		if (print == -1)
		{
			break;
		}
		cout << print << " ";
		ft[print]--;
		for (int i = 0; i < num[print].size(); i++)
		{
			ft[num[print][i]]--;
		}

	}


	
}