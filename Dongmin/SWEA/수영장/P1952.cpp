#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> schedule;
vector<int> price;
vector<bool> visited;
int minCost;

void findMinimum(int select, int month, int sum){
    if(visited[12]) {
        if(sum < minCost) {
            minCost = sum;
        }
        return;
    }
    
    if(month <= 12){
        int cost = price[select];
        if(select == 0) {
            visited[month] = true;
            sum += (schedule[month] * cost);
            for(int i=0; i<3; i++) {
                findMinimum(i, month+1, sum);
            }
            visited[month] = false;
        } else if(select == 1) {
            visited[month] = true;
            sum += cost;
            for(int i=0; i<3; i++) {
                findMinimum(i, month+1, sum);
            }
            visited[month] = false;
        } else {
            for(int i=0; i<3 && month+i <= 12; i++) {
                visited[month+i] = true;
            }
            sum += cost;
            for(int i=0; i<3; i++) {
                findMinimum(i, month+3, sum);
            }
            for(int i=0; i<3 && month+i <= 12; i++) {
                visited[month+i] = false;
            }
        }
    }
}

void solution(int casenum) {
    minCost=price[3];
    findMinimum(0, 1, 0);
    findMinimum(1, 1, 0);
    findMinimum(2, 1, 0);
    printf("#%d %d\n", casenum, minCost);
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        price.assign(4, 0);
        schedule.assign(13, 0);
        visited.assign(13,false);
        for(int i = 0; i < 4; i++) {
            cin >> price[i];
        }

        for(int i = 1; i <= 12; i++) {
            cin >> schedule[i];
        }

        solution(t);
    }
}