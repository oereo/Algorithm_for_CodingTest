#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> answer;//답을 저장하는 벡터
int maxPlayPos = 0;//현재 상태의 최대 plays값 위치를 저장하는 곳
int maxPlay = 0;//현재 상태의 최대 plays값 저장
string maxGenres;//현재 최대 play갖는 장르저장
string tempGenre;//임시로 장르를 저장
int tempSum = 0;
int maxTemp = 0;
vector<pair<string, int>> list;
vector<pair<string, int>> listTemp;//장르와 장르별 재생 수 합
int length = 0;
int cnt = 0;
//=====================================================================================
vector<int> solution(vector<string> genres, vector<int> plays) 
{
	length = plays.size();
	for (int i = 0; i < length; i++)
	{
		list.push_back(pair<string, int>(genres[i], plays[i]));
	}

	listTemp = list;

	for (int i = 0; i < length; i++)
	{
		tempGenre = list[i].first;
		tempSum = list[i].second;
		for (int j = i + 1; j < length; j++)
		{
			if (tempGenre == listTemp[j].first)
			{
				tempSum = tempSum + list[j].second;
				listTemp[j].first = " ";
				listTemp[j].second = 0;
			}
		}
		listTemp[i].second = tempSum;
	}
	while(true)
	{
		if (cnt == length)
			break;
		else
			cnt = 0;
		//장르별 노래 재생횟수 세기,
		for (int i = 0; i < length; i++)
		{
			if (maxTemp < listTemp[i].second)
			{
				maxTemp = listTemp[i].second;
				maxGenres = listTemp[i].first;
			}
		}
		for (int i = 0; i < length; i++)
		{
			if (maxGenres == list[i].first &&list[i].second > maxPlay)
			{
				maxPlayPos = i;//가장 재생 많이 된 수 위치 저장
				maxPlay = list[i].second;
			}
		}
		answer.push_back(maxPlayPos);
		list[maxPlayPos].second = 0;//위치를 저장했으므로 이제 무시
		maxPlay = 0;
		maxPlayPos = -1;
		for (int i = 0; i < length; i++)
		{
			if (list[i].first == maxGenres && list[i].second > maxPlay)
			{
				maxPlay = list[i].second;
				maxPlayPos = i;
			}
		}
		if (maxPlayPos > -1)//장르가 1개일 경우면 한번만 실행한다.
		{
			answer.push_back(maxPlayPos);
			list[maxPlayPos].second = 0;
		}
		for (int i = 0; i < length; i++)
		{
			if (list[i].first == maxGenres)
			{
				list[i].second = 0;
				listTemp[i].second = 0;
				list[i].first = " ";
			}
			if (list[i].second == 0)
			{
				cnt++;
			}
		}
		maxPlay = 0;
		maxTemp = 0;
	}
	return answer;
}
int main()
{
	vector<string> genres{"classic", "pop", "classic", "classic", "pop", "jazz", "jazz"};
	vector<int> plays{ 500, 600, 150, 800, 2500, 2000, 6000 };
	solution(genres, plays);
	
	for (int i : answer)
	{
		cout << i << endl;
	}
	
}