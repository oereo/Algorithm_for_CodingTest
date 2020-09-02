#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> Hash;
map<int, int> Remember;
int siz;
vector<int> solution(vector<string> gems) {

	int a1;
	vector<int> answer;
	answer.push_back(0);
	int len = gems.size();
	for (int i = 0; i < len; i++)
	{
		if (Hash[gems[i]] == 0) { siz++; }
		Hash[gems[i]]++;
	}
	int front = 0; int end = 0;
	map<string, int> t_hash; int cmp = 0;
	while (1)
	{
		if (t_hash[gems[end]] == 0) { cmp++; }
		t_hash[gems[end]]++;
		if (cmp == siz) { answer.push_back(end); break; }
		end++;
	}

	bool slide = false; int ptr;
	while (1)
	{
		if (slide) {
			// cout<<front<<","<<end<<endl;
			while (1)
			{

				if (end == len - 1) {
					answer[0]++; answer[1]++;
					return answer;
				}
				end++;
				t_hash[gems[end]]++;
				if (gems[end] == gems[ptr] || end == len - 1) {
					/*if(answer[1]-answer[0]>end-answer[0])
					{
						 answer[1]=end;
						 cout<<"change : "<<answer[0]<<","<<answer[1]<<endl;
					   }*/
					slide = false; break;
				}
			}
		}
		else
		{
			//cout<<front<<","<<end<<endl;
			while (1)
			{
				if (t_hash[gems[front]] > 1) {
					t_hash[gems[front]]--;
					front++;
					if (answer[1] - answer[0] > end - front)
					{
						answer[0] = front; answer[1] = end;
						// cout<<"change : "<<answer[0]<<","<<answer[1]<<endl;

					}
				}
				else
				{
					ptr = front;
					slide = true;
					break;
				}
			}

		}
	}
	return answer;
}