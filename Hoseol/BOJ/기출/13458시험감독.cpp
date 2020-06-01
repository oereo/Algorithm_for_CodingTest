#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,B,C;
vector<int> place;
long long ANS;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		place.push_back(temp);
	}
	cin >> B >> C;
	int size = place.size();
	ANS += size;
	for (int i = 0; i < N; i++)
	{
		place[i] -= B;
		if (place[i] > 0)
		{
			if (place[i] % C == 0)
			{
				ANS += place[i] / C;
			}
			else
			{
				ANS += (place[i] / C + 1);
			}
		}
	}
	
	cout << ANS;

}