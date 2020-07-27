#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int test_case;
	int T, total, answer;
	int price[4];
	int days[12];
	int result[12];
	// freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 입력 받기 & 1일권과 1달권 비교 & 비용 총합 구하기
		total = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> price[i];
		}
		for (int i = 0; i < 12; i++)
		{
			cin >> days[i];
			if (days[i] * price[0] <= price[1])
				days[i] = days[i] * price[0];
			else
				days[i] = price[1];
			total += days[i];
		}

		// 3달권과 비교
		for (int i = 0; i < 12; i++)
		{
			int diff = price[2];
			for (int j = i; j < i + 3; j++)
			{
				if (j == 12)
					break;
				diff -= days[j];
			}

			if (i - 3 >= 0)
				total = result[i - 3];

			if (diff < 0) 	// 3달권 O
				result[i] = total + diff;
			else 			// 3달권 X
				result[i] = total;

			if (i > 0 && result[i] > result[i - 1])
				result[i] = result[i - 1];
		}
		answer = result[11];

		// 1년권과 비교
		if (answer > price[3])
			answer = price[3];

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}