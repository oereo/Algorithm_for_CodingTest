/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, R, C,L;
int Map[100][100];
int visited[100][100];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };


bool check(int dir, int next)
{
	if (dir == 0)
	{
		if(next == 1 || next==2||next==5||next==6)
		{
			return true;
		}
		else return false;
	}
	else if (dir == 1)
	{
		if (next == 1 || next == 3 || next == 6 || next == 7)
		{
			return true;
		}
		else return false;
	}
	else if (dir == 2)
	{
		if (next == 1 || next == 2 || next == 4 || next == 7)
		{
			return true;
		}
		else return false;
	}
	else if (dir == 3)
	{
		if (next == 1 || next == 3 || next == 4 || next == 5)
		{
			return true;
		}
		else return false;

	}

}


struct point {
	int a;
	int b;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		deque<point> BFS;
		memset(Map, 0, sizeof(Map));
		memset(visited, 0, sizeof(visited));
		cin >> N >> M >> R >> C>>L;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> Map[i][j];
			}
		}
		int time = 1;
		int ANS = 0;
		point t;
		t.a = R; t.b = C;
		visited[R][C] = 1;
		BFS.push_back(t);
		while (time <= L)
		{
			int siz = BFS.size();
			ANS += siz;
			for (int i = 0; i < siz; i++)
			{
				point pt = BFS.front();
				BFS.pop_front();
				int a = pt.a; int b = pt.b;
				//cout << "(" << a << "," << b << ")" << endl;
				if (Map[a][b] == 1)
				{
					for (int i = 0; i < 4; i++)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 &&check(i, Map[newA][newB])&&visited[newA][newB]==0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}
				}
				else if (Map[a][b] == 2)
				{
					for (int i = 0; i < 4; i+=2)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 && check(i, Map[newA][newB])&& visited[newA][newB] == 0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}
				}
				else if (Map[a][b] == 3)
				{
					for (int i = 1; i < 4; i += 2)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 && check(i, Map[newA][newB])&& visited[newA][newB] == 0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}
				}
				else if (Map[a][b] == 4)
				{
					for (int i = 0; i < 2; i++)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 && check(i, Map[newA][newB])&& visited[newA][newB] == 0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}
				}
				else if (Map[a][b] == 5)
				{
					for (int i = 1; i < 3; i++)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 && check(i, Map[newA][newB])&& visited[newA][newB] == 0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}
				}
				else if (Map[a][b] == 6)
				{
					for (int i = 2; i < 4; i++)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 && check(i, Map[newA][newB])&& visited[newA][newB] == 0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}

				}
				else if (Map[a][b] == 7)
				{
					for (int i = 0; i < 4; i += 3)
					{
						int newA = a + dir[i][0]; int newB = b + dir[i][1];
						if (newA >= 0 && newA < N&&newB >= 0 && newB < M&&Map[newA][newB]>0 && check(i, Map[newA][newB])&&visited[newA][newB]==0) //NM 범위체크
						{
							visited[newA][newB] = 1;
							point temp; temp.a = newA; temp.b = newB;
							BFS.push_back(temp);
						}
					}
				}

			}
			time++;
		}

		cout <<"#"<<test_case<<" "<< ANS << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}