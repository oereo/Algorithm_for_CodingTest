## SW Expert Academy
### 1952. [모의 SW 역량테스트] 수영장

문제 출처: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&&&
    
#### 문제

     각 달의 수영장 이용 계획과 이용권의 금액이 주어진다. 이용권 구매 경우의 수 중 지출 금액이 최소인 경우 그 금액을 반환하여 출력한다.


#### 접근

  Brute-Force 
    
    1월부터 1일 이용권을 이용하는 경우, 1달 이용권을 이용하는 경우, 3달 이용권을 이용하는 경우를 전부 탐색한다.
    
    (1년 이용권을 이용하는 경우는 하나의 case 뿐이므로 최종 반환 minimum 초기 값으로 설정한다.)
    
    -> DFS 이용

 Time Complexity는 대략 T(n) <= O(3^n) (n은 달의 수) 12월까지 존재하므로 상한 3^12 이므로 DFS로 접근하여도 대략 530,000 가지수로 충분하다.

#### 시행착오
 
  Base case를 visited 배열을 두어 12월까지 탐색을 완료했다면 (visited[12] == true) leaf 노드로 판단하는 것으로 설계했는데 call stack을 반환하고 다른 노드를 탐색할 때 탐색 중이었던 달을 false로 바꾸어 줘야 하는데 놓쳤다.

  또한 굳이 visited 배열을 두지 않고 현재 탐색하고 있는 달을 의미하는 month 변수만 두어도 될 것 같다. 


#### 최종 구현
 
 앞서 설명한 방식이 전부
 
#### 개선
 - Branch and Bound

    bound function을 설정하여 BFS로 탐색할 수 있다.
    
    ex))

 - Back-tracking

    현재 갱신된 minCost보다 커지는 경우 미리 call stack을 반환하여 탐색 노드를 감소시킬 수 있다.

    ex))

  - Dynamic Programming

    DP로도 가능함을 스터디를 통해 확인되었다. 나중에 시도해볼것.