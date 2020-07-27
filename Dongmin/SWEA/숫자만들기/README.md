## SW Expert Academy
### 4008. [모의 SW 역량테스트] 숫자 만들기

문제 출처: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH&categoryId=AWIeRZV6kBUDFAVH&categoryType=CODE
    
#### 문제

     일반적인 사칙 연산 순서를 무시하고 왼쪽부터 차례로 계산할 때, 숫자 set과 각 연산자의 개수가 주어졌다면 나올 수 있는 결과 값의 최대값과 최소값의 차를 계산하여 반환한다.


#### 접근
 
 Brute-Force
  
  숫자 set이 최대 12개까지 주어지고 즉, 연산자는 최대 11개까지 주어진다. 하지만 사칙연산은 4가지 밖에 없으므로 11개 연산자들을 나열하는 경우의 수는 11! 보다 훨씬 적다. 

  더군다나 11!은 대략 30,000,000 이므로 모든 경우를 탐색하는 알고리즘도 충분히 허용할만 하다.

 중복된 연산자의 순열을 구하면 되므로 중복 순열 문제이다.
 next_permutation을 사용하면 될 것 같았다.

#### 시행착오
 없었다.
  


#### 최종 구현
 
 next_permutation을 돌릴 vector을 설정하기 위해 opnum이라는 vector를 선언했다. 입력에서 주어지는 연산자 개수를 opnum vector에 +는 0으로, -는 1, *는 2, /는 3으로 하여 각각 push_back 하였다.

 그리고 next_permutation(opnum.begin(), opnum.end()) 하면 모든 중복 순열의 경우를 do-while 문 내에서 opnum을 재배치하여 탐색한다.

 각 연산의 결과를 result 배열에 저장하고 그 최대값과 최솟값을 min_element와 max_element를 이용하여 얻었다.
 
#### 개선

 ???
 