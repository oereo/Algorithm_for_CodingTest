#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool Right;
int Map[4][3];
int R[2] = { 3,2 };
int L[2] = { 3,0 };
string answer = "";
string solution(vector<int> numbers, string hand) {
	if (hand == "right") { Right = true; }
	else { Right = false; }

	int len = numbers.size();
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			int a = (numbers[i] - 1) / 3; int b = (numbers[i] - 1) % 3;
			L[0] = a; L[1] = b;
			answer += "L";
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			int a = (numbers[i] - 1) / 3; int b = (numbers[i] - 1) % 3;
			R[0] = a; R[1] = b;
			answer += "R";
		}
		else
		{
			int a; int b;
			a = (numbers[i] - 1) / 3;  b = (numbers[i] - 1) % 3;
			if (numbers[i] == 0)
			{
				a = 3; b = 1;
			}

			int Rd = abs(R[0] - a) + abs(R[1] - b);
			int Ld = abs(L[0] - a) + abs(L[1] - b);
			if (Rd > Ld)
			{
				L[0] = a; L[1] = b;
				answer += "L";
			}
			else if (Ld > Rd)
			{
				R[0] = a; R[1] = b;
				answer += "R";
			}
			else
			{
				if (Right) {
					R[0] = a; R[1] = b;
					answer += "R";
				}
				else {
					L[0] = a; L[1] = b;
					answer += "L";
				}
			}



		}

	}

	return answer;
}