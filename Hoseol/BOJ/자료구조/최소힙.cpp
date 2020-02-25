#include <iostream>
#include <queue>
#include <functional>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> Q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k == 0)
		{
			if (Q.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << Q.top() << "\n";
				Q.pop();
			}

		}
		else
		{
			Q.push(k);
		}

	}
}