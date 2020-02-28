// 문제 설명
// 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

// 예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

// 문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

// 제한 조건
// number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
// k는 1 이상 number의 자릿수 미만인 자연수입니다.
// 입출력 예
// number	k	return
// 1924	2	94
// 1231234	3	3234
// 4177252841	4	775841
// 출처

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue< int, vector<int>, less<int> > q;
queue<pair<int, int>> pairq;

string solution(string number, int k) {
    string answer = "";
    int length =  number.size();
    char maxnumber = 0;
    int ind = 0;
    
    //for(int i = 0; i<number.size(); i++){
    //    q.push(number[i]);
    //    pairq.push({i, nnumberp[i]});
    // }
    
    
    
    for(int i = 0; i<length-k; i++){
        maxnumber = 0;
        for(int j = ind; j<=i+k;j++){
            if(maxnumber<number[j]){
                ind = j+1;
                maxnumber = number[j];
            }
        }
        answer += maxnumber;
    }
    
    return answer;
}

// next_permutation을 이용해서 조합을 만들었지만 시간초과가 나기에 효율적이지는 못한다.
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// bool desc(string a, string b){
//     return a > b;
// }

// string solution(string number, int k) {
//     string answer = "";
//     string str = "";
//     vector<int> n;
//     vector<string> result;
//     //cout << number.size();
// 	for(int i=0; i<number.size(); i++){
// 		n.push_back(number[i]-48);
//         //cout << number[i];
// 	}

// 	vector<int> ind;
// 	int key = number.size()-k;

// 	for(int i=0; i<key; i++){
// 		ind.push_back(1);
// 	}


// 	for(int i=0; i<n.size()-key; i++){
// 		ind.push_back(0);
// 	}

// 	sort(ind.begin(), ind.end());

	
// 	do{
// 		for(int i=0; i<ind.size(); i++){
// 			if(ind[i] == 1){
//                 str = str+to_string(n[i]);
// 			}
// 		}
//         //cout << str;
//         result.push_back(str);
//         str = "";
        
// 		//printf("\n");

// 	}while(next_permutation(ind.begin(), ind.end()));
//     sort(result.begin(), result.end(), desc);
//     answer = result[0];
//     return answer;
// }