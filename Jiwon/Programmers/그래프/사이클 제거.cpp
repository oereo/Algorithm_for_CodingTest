/*
n개의 노드로 구성된 그래프에서 하나의 노드만을 제거해서 사이클이 없도록 만들고 싶습니다.

노드의 개수 n, 노드간의 연결 edges가 매개변수로 주어질 때, 노드를 딱 하나 제거해서 그래프를 사이클이 없도록 
만들 수 있다면 해당 노드의 번호를 return 하도록 solution 함수를 완성하세요.
단, 그런 노드가 없다면 0을 return하고, 여러 개라면 노드의 번호의 합을 return하세요.

예:
n	edges	                                                        result
4	[[1,2],[1,3],[2,3],[2,4],[3,4]]	                                5
8	[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7],[7,8],[8,1],[2,7],[3,6]]	0
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    return answer;
}