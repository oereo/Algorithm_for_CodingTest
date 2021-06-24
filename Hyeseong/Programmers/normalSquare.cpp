#include <iostream>
using namespace std;

long long gcd(int a, int b) {
	long c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long solution(int w, int h) {
	long long answer = 1;
	long long W = w;
	long long H = h;
	long long temp = w + h - gcd(w, h);

	answer = W * H - temp;

	return answer;
}