#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector<int>> map;


int main()
{
	int N, M;
	int tempMinVal = 10000000000;//현재 집과 치킨집들 사이의 최단거리
	int tempVal;
	int res = 0;
	int chickenNum = 0;
	int houseNum = 0;
	cin >> N >> M;
	map.resize(N+1, vector<int>(N+1, 0));
	pair<int, int> housePos[101];//N의 최대값50, 집의개수 최대 2N
	pair<int, int> chickenPos[14];//치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.
	int finalres = 10000000000;
	int temp1 = 0;//치킨집위치저장 인덱스
	int temp2 = 0;//집위치저장 인덱스
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				chickenNum++;
				chickenPos[temp1++] = make_pair(i, j);

			}
			else if (map[i][j] == 1)
			{
				houseNum++;
				housePos[temp2++] = make_pair(i, j);
			}
		}

	}

	if (chickenNum == M)
	{

		for (int i = 0; i < houseNum; i++)
		{
			for (int j = 0; j < chickenNum; j++)
			{
				tempVal = abs(housePos[i].first - chickenPos[j].first) + abs(housePos[i].second - chickenPos[j].second);
				if (tempMinVal > tempVal)
					tempMinVal = tempVal;
			}
			res = res + tempMinVal;
			tempMinVal= 10000000000;
		}
		finalres = res;
	}
	else
	{
		bool Select[14] = {0};
		for(int i = 0; i< M;i++)//M개 선택해야할 수 만큼을 1로표시, 나머지는 다 0으로 표시
			Select[i] = 1;
		int tempSum = 0;//선택한 M개일때마다 도시의 치킨거리를 저장
		vector<int> choosePos;
		
		do {
			for (int i = 0; i < chickenNum; i++) 
			{
				if (Select[i]) 
					choosePos.push_back(i);
			}
		} while (prev_permutation(Select, Select + chickenNum));//선택할 경우의 수를 모두 저장

		
		int temp=0;
		int h = 0;
		int c = choosePos.size() / M;
		while (c>0)
		{
			for (int i = 0; i < houseNum; i++)
			{
				for (int j = h; j < h+M; j++)
				{
					temp = choosePos[j];
					tempVal = abs(housePos[i].first - chickenPos[temp].first) + abs(housePos[i].second - chickenPos[temp].second);
					
					if (tempMinVal > tempVal)
						tempMinVal = tempVal;
				}
				res = res + tempMinVal;
				tempMinVal = 10000000000;
			}//선택한 M의 치킨집에 대해 각 치킨거리를 저장

			if (finalres > res)
				finalres = res;//최단 선택한 M의 도시치킨거리를 저장
			h = h + M;
			res = 0;
			c--;
		}
	
	}
	
	cout << finalres << endl;

}