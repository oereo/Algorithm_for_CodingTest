
## SW Expert Academy
### 2115. [모의 SW 역량테스트] 벌꿀채취

문제 출처: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu&categoryId=AV5V4A46AdIDFAWu&categoryType=CODE
    
#### 문제

     두 명의 일꾼이 있고, 각 일꾼은 N*N 크기 벌통 그리드의 임의의 한 행에서 연속으로 M개의 벌통을 선택한다. 선택된 연속된 M개의 벌통 안 꿀 양의 합이 C를 넘지 않도록 채집하는 가지 수 중에서 각 벌통의 꿀 양의 제곱의 합이 최대가 되도록 하는 경우, 그 합을 반환하는 문제이다.


#### 접근
 어느 일꾼이든 각 일꾼은 그 제곱의 합이 가장 큰 경우와 두번째로 큰 경우를 할당 받으면 되는데 문제를 크게 두 부분으로 쪼갤 수 있다.

 1. 연속된 M개의 벌통에서 그들의 제곱의 합이 가장 크도록 선택하는 부분
 2. 그 제곱의 합이 가장 큰 경우와 두번째로 큰 경우를 찾아 합을 계산하는 부분

#### 시행착오
 처음에는 1번 부분에서 그리디하게 가장 작은 부분을 제거해가면서 합이 C가 넘지 않는 순간에 그 조합을 반환하도록 설계했지만 Test Case 3번에서 통과되지 않았다.

    Test Case #3
    3 3 10
    7 2 9
    6 6 6
    5 5 7

    마지막 줄에서 이전 알고리즘은 7^2 = 49를 반환하지만 최대값은 5^2 + 5^2 = 50이다.

 그래서 전체 케이스를 탐색하도록 DFS로 수정하였다.
 (시간 복잡도: O(2^M))
 
 1번 알고리즘을 따로 getMaxProfit(...)이라는 메서드로 따로 분리하여 2번 부분을 계산할 때 이중 for문으로 max 값을 업데이트 하는 방식으로 설계했지만 exponential TC인 1번 알고리즘을 ((N-M+1)*N)^2 번까지 반복하는 최악의 복잡도를 보여서 시간 초과되었다.

 그래서 반복되는 계산을 줄이기 위해 profits이라는 dp table을 미리 계산해놓고 이중 for문에서 참조하도록 수정했다.


#### 최종 구현
 1번 알고리즘의 전체 탐색은 DFS로 

 ` `  ` 
   void search(vector<int> row, vector<int>& subset, int& max, int index);
 ` `  `

 method에서 진행한다. row는 선택되는 연속된 M개의 벌통 data이고, subset은 현재 탐색을 진행하고 있는 부분 집합이다. max는 제곱의 합이 최대인 값으로 현재 subset의 것과 비교하여 크면 갱신한다.
 
 index는 현재 row에서 탐색하고 있는 index 값이다.
 다음 call stack은 
 
 ` ` `
 search(row, subset, max, index+1)
 ` ` `

와 같이 호출한다. 

base case는 합이 C를 넘어가거나 index가 row의 크기보다 클 때이고 아무일도 하지 않고 CPU 제어를 반환한다.

두 일꾼이 연속된 벌통을 선택하는 경우를 탐색하는 이중 for문에서는 서로의 선택이 겹치지 않도록 선택한 row가 같은 경우, col은 col2 >= col + M 가 되도록 선택하고 그렇지 않은 경우 어떤 선택이든 허용한다. 

하지만 제출 test case에서는 같은 row의 선택을 허용하지 않는 오류를 포함하고 있어 최종 구현은 같은 row 내의 선택은 continue 처리하였다.

#### 개선
???