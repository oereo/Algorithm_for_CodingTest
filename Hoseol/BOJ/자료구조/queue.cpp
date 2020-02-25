#include <iostream>
#include <string>
using namespace std;
int q[10101];
int h = 0, t = -1;
char buf[111];
int dat;

int main()
{
	int num;
	//cout << "명령의수를 입력하시오" << endl;
	cin >> num;
	while (num > 0) {
		//cout << "명령을 입력하라" << endl;

		string f;
		cin >> f;

		if (f == "push")
		{
			cin >> dat;
			q[t + 1] = dat;
			t++;

		}

		if (f == "pop")
		{
			if (h <= t)
			{
				cout << q[h] << endl;
				h++;
			}

			else
			{
				cout << -1 << endl;
			}
		}

		if (f == "size")
		{
			cout << t - h + 1 << endl;
		}

		if (f == "empty")
		{
			if (h > t)
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}

		}

		if (f == "front")
		{
			if (h > t)
			{
				cout << -1 << endl;
			}
			else
				cout << q[h] << endl;
		}

		if (f == "back")
		{
			if (h > t)
			{
				cout << -1 << endl;
			}
			else
				cout << q[t] << endl;
		}



		num--;
	}
}