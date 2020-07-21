/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> number;
vector<int> result;
int total ;
int cnt ;

void makeNum(int num, int total, int plus_cnt, int minus_cnt, int multi_cnt, int div_cnt, int cnt, int N) { // 연산자 수

	if ( N-1 == cnt ) {
		//cout << num<<" ";
		result.push_back(num);
		cnt = 0;
		
	}
	total--;
	if (plus_cnt > 0) {
		makeNum(num + number[cnt+1], total, plus_cnt - 1, minus_cnt, multi_cnt, div_cnt, cnt+1, N);
	}
	if (minus_cnt > 0) {
		makeNum(num - number[cnt+1], total, plus_cnt, minus_cnt - 1, multi_cnt, div_cnt, cnt+1, N);

	}
	if (multi_cnt > 0) {
		makeNum(num * number[cnt+1], total, plus_cnt, minus_cnt, multi_cnt - 1, div_cnt, cnt+1, N);

	}
	if (div_cnt > 0) {
		makeNum(num / number[cnt+1], total, plus_cnt, minus_cnt, multi_cnt, div_cnt - 1, cnt+1, N);

	}
	
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int plus;
	int minus;
	int multi;
	int div;
	int temp;


	//freopen("sample_input (2).txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		cnt, total = 0;
		cin >> N;
		cin >> plus >> minus >> multi >> div;
		total = plus + minus + multi + div;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			number.push_back(temp);
		}

		makeNum(number[0], total, plus, minus, multi, div, 0, N);
		sort(result.begin(), result.end());
		cout<<"#"<<test_case<<" "<<result[result.size()-1]-result[0]<<endl;
		//cout << result[result.size()-1 ] << endl;
		number.clear();
		result.clear();
		/*for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}*/
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}