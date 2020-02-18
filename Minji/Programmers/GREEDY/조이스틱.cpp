#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int change[n];
    for(int i = 0; i < n; i++){
        if(name[i] < 'N')
            change[i] = name[i] - 'A';
        else
            change[i] = 'Z' - name[i] + 1;
    }
    
    int cnt_front = 0;
    int cnt_back = 0;
    int cnt_hf = 0;
    int cnt_hb = 0;
    
    for(int i = 1; i < n; i++){
        if(change[i] != 0)
            cnt_front = i;
    }
    
    for(int i = 1; i < n; i++){
        if(change[n-i] != 0)
            cnt_back = i;
    }
    for(int i = 1; i <= n/2; i++){
        if(change[i] != 0)
            cnt_hf = i;
        if(change[n-i] != 0)
            cnt_hb = i;
    }
    
    answer += min(min(cnt_front, cnt_back), cnt_hf*2 + cnt_hb);
    answer += accumulate(change, change+n, 0);
    return answer;
}
