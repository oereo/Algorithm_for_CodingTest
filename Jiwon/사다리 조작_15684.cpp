/**/

#include <iostream>
#include <vector>
using namespace std;

int cnt[11];
int temp[11];

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL);

    int N, M, H;
    cin >> N >> M >> H;

    int answer = 0;

    int a, b;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cnt[b]++;
        cnt[b+1]++;
    }

    for(int i = 0; i < N-1; i++){
        if(cnt[i] % 2 == 0){
            continue;
        }
        else{
            cnt[i]++;
            cnt[i++]++;
            answer++;
        }
    }


    if(answer < 4){
        cout << answer;
    }
    else{
        cout << "-1";
    }

    return 0;   
}