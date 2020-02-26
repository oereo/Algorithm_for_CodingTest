#include <iostream>
#include<algorithm>
// #include<map>

using namespace std;

int a[500] = { 0 };
int b[500] = { 0 };
int z = 0;
int result[1000] = { 0 };


int main()
{
	int z;
	int next;
	//map<int, int> m;
	cin >> z;

	for (int i = 0; i < z; i++) {
		cin >> a[i] >> b[i];
		//m[a[i]] = b[i];
	}

	for (int i = z - 1; i >= 0; i--) {
		next = i + a[i];
		if (next >= z + 1) {
			result[i] = max(result[i + 1], 0);
			continue;
		}

		result[i] = max(result[next] + b[i], result[i + 1]);


	}
	sort(result, result + z);
	
		cout << result[z-1] << endl;
		//	for (int i = 0; i < z; i++) {
		//	cout << result[i] << endl;
		//  }
	return 0;
	
}