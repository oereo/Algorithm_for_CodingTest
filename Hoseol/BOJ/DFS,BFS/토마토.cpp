#include <iostream>
#include <vector>
using namespace std;

struct point {
	int n;
	int m;
};
int map[2005][2005];
vector<point> Tbox;
int newT;
int days;
bool IsNew=true;
int start;
void up(point a,int n, int m)
{
	
	point tmp;
	if (a.n - 1 >= 0)
	{
		if (map[a.n - 1][a.m] == 0) {
			IsNew = true;
			map[a.n - 1][a.m] = 1;
			tmp.n = a.n - 1;
			tmp.m = a.m;
			Tbox.push_back(tmp);
		}
	}

}
void down(point a,int n, int m)
{
	
	point tmp;
	if (a.n + 1 <= n)
	{
		if (map[a.n + 1][a.m] == 0) {
			map[a.n + 1][a.m] = 1;
			IsNew = true;
			tmp.n = a.n + 1;
			tmp.m = a.m;
			Tbox.push_back(tmp);
		}
	}

}
void right(point a,int n, int m)
{
	
	point tmp;
	if (a.m + 1 <= m)
	{
		if (map[a.n][a.m + 1] == 0) {
			map[a.n][a.m + 1] = 1;
			IsNew = true;
			tmp.n = a.n;
			tmp.m = a.m + 1;
			Tbox.push_back(tmp);
		}
	}

}
void left(point a, int n, int m)
{
	
	point tmp;
	if (a.m - 1 >= 0)
	{
		if (map[a.n][a.m - 1] == 0) {
			IsNew = true;
			map[a.n][a.m - 1] = 1;
			tmp.n = a.n;
			tmp.m = a.m - 1;
			Tbox.push_back(tmp);
		}
	}

}


int main()
{   
	point temp;
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				temp.n = i;
				temp.m = j;
				Tbox.push_back(temp);
			}
		}
	}
	while(!Tbox.empty())
	{
		IsNew = false;
		newT = Tbox.size();
		
		
		for (int i = 0; i < newT; i++) {
			temp = Tbox[i];
			up(temp, N-1, M-1);
			down(temp, N-1, M-1);
			right(temp, N-1, M-1);
			left(temp, N-1, M-1);
			
		}
		Tbox.erase(Tbox.begin(), Tbox.begin()+ newT);
		if (IsNew == true) {
			days++;
		}
		else
		{
			break;
		}
		
	
		
	}
	bool check=true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			
			if (map[i][j] == 0)
			{
				check=false;
			}
		}
	}
	if (check == false)
	{
		cout << -1;
	}
	else
	{
		cout << days;
	}
}

