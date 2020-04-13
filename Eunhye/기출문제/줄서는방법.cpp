#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> answer(n);
	
	for (int i = 0; i < n; i++)
	{
		answer[i] = i + 1;
	}

	int count = 0;

	do {
		count++;
		if (count == k)
		{
			for (int i = 0; i < n; i++)
			{
				cout << answer[i] << " ";
			}
			break;
		}
	} while (next_permutation(answer.begin(), answer.end()));

}
