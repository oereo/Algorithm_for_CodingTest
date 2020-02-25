#include <iostream>
using namespace std;

int max[500000];
struct q {
	int size;
	int send=-1;	
};

q stack[500000];
void search(int i)
{	
	if (max[i-1] >= stack[i].size) {
		int j = i - 1;
		while (j >= 0) {
			if (stack[i].size <= stack[j].size)
			{
				stack[i].send = j;
				break;
			}
			j--;
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	cin >> stack[0].size;
	max[0] = stack[0].size;
	for (int i = 1; i < n; i++)
	{
		cin >> stack[i].size;
		if (max[i-1]<stack[i].size){
			max[i] = stack[i].size;
		}
		else
		{
			max[i] = max[i - 1];
		}
	}
	
	
	for (int i = n - 1; i >= 1; i--)
	{

		search(i);
	}

	for (int i = 0; i < n; i++)
	{
		
			stack[i].send++;
		
		cout << stack[i].send << " ";

		
	}


}