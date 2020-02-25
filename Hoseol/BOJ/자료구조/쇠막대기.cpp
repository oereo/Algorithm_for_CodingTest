#include <iostream>
#include <string.h>
using namespace std;

char stack[100001] = { 0, };
char stick[100001];
int C;
int countF = 0;

int main()
{
	cin >> stack;

	int temp = strlen(stack);
	for (int i = 0; i < temp; i++)
	{
		if (stack[i] == 0) { break; }
		
		else if (stack[i] == '(')
		{
			stick[countF] = i;
			countF++;
			C++;
		}
		else if (stack[i] == ')'&&i >= 1)
		{
			countF--; //이다음 반복문돌떄, 레이저쏘면 안잘리기떄문.
			if (stack[i - 1] == '(')
			{
				C += countF-1; //-1은 아까 (추가할때 count에 추가했기때문
			}	
		}
	}
	cout << C;
}