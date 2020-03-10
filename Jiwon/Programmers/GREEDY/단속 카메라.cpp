/*
고속도로를 이동하는 모든 차량이 고속도로를 이용하면서 단속용 카메라를 한 번은 만나도록 카메라를 설치하려고 합니다.

고속도로를 이동하는 차량의 경로 routes가 매개변수로 주어질 때, 모든 차량이 한 번은 단속용 카메라를 만나도록 하려면 
최소 몇 대의 카메라를 설치해야 하는지를 return 하도록 solution 함수를 완성하세요.

routes에는 차량의 이동 경로가 포함되어 있으며 routes[i][0]에는 i번째 차량이 고속도로에 진입한 지점, routes[i][1]에는 i번째 차량이 고속도로에서 나간 지점이 적혀 있습니다.
차량의 진입/진출 지점에 카메라가 설치되어 있어도 카메라를 만난것으로 간주합니다.

예:
routes	                                    return
[[-20,15], [-14,-5], [-18,-13], [-5,-3]]	2
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;    
    sort(routes.begin(),routes.end());
    answer++;
    int cameraloc = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(cameraloc >= routes[i][1]){
           cameraloc = routes[i][1]; 
        }
        if(cameraloc < routes[i][0]){
            answer++;
            cameraloc = routes[i][1]; 
        }
    }
    return answer;
}