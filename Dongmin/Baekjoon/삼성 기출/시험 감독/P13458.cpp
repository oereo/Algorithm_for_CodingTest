// long long 데이터타입 주의
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int general_cover, deputy_cover;
vector<int> num_of_applicants;

void getInput() {
    cin >> N;
    num_of_applicants.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin >> num_of_applicants[i];
    }
    cin >> general_cover >> deputy_cover;
}

void solution() {
    long long ans = N;
    for(int test_site=0; test_site<N; test_site++) {
        int applicants_covered_by_deputy = num_of_applicants[test_site] - general_cover;
        int deputy_number = 0;
        if(applicants_covered_by_deputy > 0) {
            deputy_number = applicants_covered_by_deputy / deputy_cover;
            if(applicants_covered_by_deputy % deputy_cover != 0) {
                deputy_number += 1;
            }
        }      
        ans += deputy_number;
    }
    printf("%lld", ans);
}

int main() {
    getInput();
    solution();
}