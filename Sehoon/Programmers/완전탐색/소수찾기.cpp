// 문제 설명
// 한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

// 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

// 제한사항
// numbers는 길이 1 이상 7 이하인 문자열입니다.
// numbers는 0~9까지 숫자만으로 이루어져 있습니다.
// 013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
// 입출력 예
// numbers	return
// 17	3
// 011	2
// 입출력 예 설명
// 예제 #1
// [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

// 예제 #2
// [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

// 11과 011은 같은 숫자로 취급합니다

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int check[10] = {0};
vector<char> temp;
vector<int> prime{0,0};
vector<int> prime_n;
int solution(string numbers) { // 에라토스테네스의 체
    int answer = 0;
    int length = numbers.size();
    string str = "";
    string numbers_c = numbers;
    
    for(int i = 0; i<length; i++){
        temp.push_back(numbers[i]);
       
    }
    sort(temp.begin(), temp.end());
    
    for(int i = length-1; i>=0; i--){
        str += temp[i];
    }
    //cout << str;
    int str_size = stoi(str); // 최대값
    for(int i = 2; i<=str_size; i++){
        prime.push_back(i);
    }
    for(int i =2; i<=str_size; i++){
        if(prime[i] == 0) continue;
        for(int j = i+i; j<=str_size; j+=i){
            prime[j] = 0;
        }
    }
    
    for (int i = 2; i <= str_size; i++) {
        if (prime[i] != 0){
            prime_n.push_back(prime[i]);
            //cout << prime[i] << " ";
        }
           
    }
    int length_prime_n = prime_n.size();
    
        for(int i = 0; i<prime_n.size();i++){
            int index = 0;
            string tt = to_string(prime_n[i]);
            //cout << tt;
            for(int j = 0; j<tt.size(); j++){
                
                 if(numbers.find(tt.substr(j, 1)) < numbers.size()){
                     //cout << numbers.find(tt.substr(j, 1)) << "a";
                     index++;
                     numbers[numbers.find(tt.substr(j, 1))] = 10001;
                 }
                
            }
            //cout << index;
            if(index ==tt.size()){
                //cout << "소수 :" << prime_n[i]<< " ";
                prime_n.erase(prime_n.begin()+i);
                i--;
                
            }
            numbers = numbers_c;

    }
    //cout << "/";
    //cout << tt << " " << index << " " ;
    //for (int i = 0; i<prime_n.size(); i++) {
        
    //        cout << prime_n[i] << " ";
        
    //}
    
    answer = length_prime_n-prime_n.size();
    
 
    return answer;
}