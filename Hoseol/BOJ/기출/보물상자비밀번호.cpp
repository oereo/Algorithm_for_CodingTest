#include <algorithm>
#include <map>
#include<iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
vector<int> ANS;
map<char, int> Hash;
void initHash()
{
	Hash['1'] = 1;
	Hash['2'] = 2;
	Hash['3'] = 3;
	Hash['4'] = 4;
	Hash['5'] = 5;
	Hash['6'] = 6;
	Hash['7'] = 7;
	Hash['8'] = 8;
	Hash['9'] = 9;
	Hash['A'] = 10;
	Hash['B'] = 11;
	Hash['C'] = 12;
	Hash['D'] = 13;
	Hash['E'] = 14;
	Hash['F'] = 15;
}

int main(int argc, char** argv)
{
	initHash();
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N; int K; ANS.clear();
		cin >> N >> K;
		int len = N / 4;
		string t;
		cin >> t;
		for (int time = 0; time < len; time++)
		{
			for (int i = 0; i < N; i++)
			{
				if ((i + 1) % len == 0)
				{
					int num = 0;
					int sixt = len - 1;
					for (int j = (i + 1) - len; j <= i; j++)
					{
						num += (Hash[t[j]] * pow(16, sixt));
						sixt--;
					}
					ANS.push_back(num);
				}
			}
			string temp = t;
			for (int i = 1; i <= N; i++)
			{
				if (i == N)
				{
					t[0] = temp[N - 1];
				}
				else {
					t[i] = temp[i - 1];
				}
			}



		}
		sort(ANS.begin(), ANS.end());
		ANS.erase(unique(ANS.begin(), ANS.end()), ANS.end());
		int  siz = ANS.size();
		/*for (int i = 0; i < ANS.size(); i++)
		{
			cout << ANS[i] << " ";
		}*/
		cout <<"#"<<test_case<<" "<< ANS[siz- K]<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}