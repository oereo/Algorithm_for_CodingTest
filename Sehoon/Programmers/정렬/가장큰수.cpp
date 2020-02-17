// 수정중 : next_permutation 을 했지만 시간초과가 나는 것 같음.

// 가장 큰 수
// 문제 설명
// 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

// 예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

// 0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

// 제한 사항
// numbers의 길이는 1 이상 100,000 이하입니다.
// numbers의 원소는 0 이상 1,000 이하입니다.
// 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
// 입출력 예
// numbers	return
// [6, 10, 2]	6210
// [3, 30, 34, 5, 9]	9534330

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b)
{
	return (b+a) < (a+b);
}


//bool 함수이름 (const 변수형& a, const 변수형& b){
//    return (a가 b보다 앞에 올 조건);
//}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
	
	for (int i = 0; i < numbers.size(); i++) 
	{
		str.push_back(to_string(numbers[i]));
	}

	sort(str.begin(), str.end(), comp); 
	
	for (int i = 0; i < str.size(); i++) 
	{
		answer += str[i];
	}
    
	if (answer[0] == '0') 
	{
		return "0";
	}
    //answer = to_string(numbers[0]);
    return answer;
}