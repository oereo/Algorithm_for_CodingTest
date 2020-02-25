#include <iostream>
#include <algorithm>
using namespace std;
int pl, mi, mu, di;
int N;
int A[105];
int mx = -1000000001, mn = 1000000001;
int CT;
void DFS(int b,int pl_n,int mi_n, int mu_n, int di_n, int cnt,int value )
{
	//cout << "값"<<b<<value << endl;
	if (cnt == CT)
	{
		mx=max(value,mx);
		mn = min(value, mn);
		return;
	}
	if (pl_n > 0)
	{
		DFS( b+1, pl_n-1, mi_n, mu_n, di_n, cnt+1, value+A[b]);
	}
	if (mi_n > 0)
	{
		DFS( b + 1, pl_n, mi_n-1, mu_n, di_n, cnt + 1, value - A[b]);
	}
	if (mu_n > 0)
	{
		DFS( b + 1, pl_n , mi_n, mu_n-1, di_n, cnt + 1, value * A[b]);
	}
	if (di_n > 0)
	{
		DFS( b + 1, pl_n, mi_n, mu_n, di_n-1, cnt + 1, value / A[b]);
	}

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cin >> pl >> mi >> mu >> di;
	CT = pl + mi + mu + di;
	DFS( 1, pl, mi, mu, di, 0,A[0]);
	cout << mx << endl;
	cout << mn;

}

