#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
typedef struct {
    int num, freq;
} NumFreq;
bool cmp(const NumFreq& a, const NumFreq& b) {
    return a.freq==b.freq ? a.num < b.num : a.freq < b.freq;
}
int r,c,k;
int rnum, cnum;
int arr[500][500];
void getInput() {
    cin >> r >> c >> k;
    rnum = 3, cnum = 3;
    memset(arr, 0, sizeof(arr));
    for(int i=1; i<4; i++) {
        for(int j=1; j<4; j++) {
            cin >> arr[i][j];
        }
    }
}

void Roperation() {
    int max = 0;
    for(int i=1; i<=rnum; i++) {
        map<int, int> freq;
        vector<NumFreq> temp;
        for(int j=1; j<=cnum; j++) {
            int num = arr[i][j];
            if(num != 0) {
                if(!freq.count(num)) {
                    temp.push_back(NumFreq{num, 0});
                    freq[num] = 1;
                }
                else freq[num] +=1 ;
            }
        }

        for(int m=0; m < freq.size(); m++) {
            temp[m].freq = freq[temp[m].num];
        }
        int new_cnum = freq.size() * 2;
        sort(temp.begin(), temp.end(), cmp);
        if(new_cnum > max) max = new_cnum;
        if(new_cnum >= cnum) {
            cnum = new_cnum;
            for(int m=1; m<=new_cnum; m+=2) {
                arr[i][m] = temp[m/2].num;
                arr[i][m+1] = temp[m/2].freq;
            }
        }
        else {
            for(int m=1; m<=cnum; m+=2) {
                if(m<=new_cnum) {
                    arr[i][m] = temp[m/2].num;
                    arr[i][m+1] = temp[m/2].freq;
                }
                else {
                    arr[i][m] = 0;
                    arr[i][m+1] = 0;
                }
            }
        }
    }

    cnum = max;
}

void Coperation() {
    int max = 0;
    for(int i=1; i<=cnum; i++) {
        map<int, int> freq;
        vector<NumFreq> temp;
        for(int j=1; j<=rnum; j++) {
            int num = arr[j][i];
            if(num != 0) {
                if(!freq.count(num)) {
                    temp.push_back(NumFreq{num, 0});
                    freq[num] = 1;
                }
                else freq[num] +=1 ;
            }
        }

        for(int m=0; m < freq.size(); m++) {
            temp[m].freq = freq[temp[m].num];
        }
        int new_rnum = freq.size() * 2;
        if(new_rnum > max) max = new_rnum;
        sort(temp.begin(), temp.end(), cmp);
        if(new_rnum >= rnum) {
            rnum = new_rnum;
            for(int m=1; m<=new_rnum; m+=2) {
                arr[m][i] = temp[m/2].num;
                arr[m+1][i] = temp[m/2].freq;
            }
        }
        else {
            for(int m=1; m<=rnum; m+=2) {
                if(m<=new_rnum) {
                    arr[m][i] = temp[m/2].num;
                    arr[m+1][i] = temp[m/2].freq;
                }
                else {
                    arr[m][i] = 0;
                    arr[m+1][i] = 0;
                }
            }
        }
    }

    rnum = max;
}
void solution() {
    int ans = 0;
    while(arr[r][c] != k) {
        if(ans == 100) {
            ans=-1;
            break;
        }
        if(rnum >= cnum) {
            Roperation();
        }
        else {
            Coperation();
        }

        for(int i=1; i<=rnum; i++) {
            for(int j=1; j<=cnum; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout <<endl << endl;
        ans += 1; 
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
    return 0;
}