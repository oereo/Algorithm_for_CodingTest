#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, C;
vector<vector<int> > honey;

void getInput() {
    cin >> N >> M >> C;
    honey.assign(N, vector<int>(N, -1));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> honey[i][j];
        }
    }
}

int getSum(vector<int> arr) {
    int sum = 0;
    for(int el:arr) {
        sum += el;
    }
    return sum;
}


void search(vector<int> row, vector<int>& subset, int& max, int index) {
    int squaredSum = 0;
    int sum = getSum(subset);
    for(int i=0; i<subset.size(); i++) {
        squaredSum += (subset[i]*subset[i]);
    }

    if(sum <= C &&squaredSum > max) {
        max = squaredSum;
    }

    // base cond
    if(sum > C || index == row.size()) {
        return;
    }
    else {
        subset.push_back(row[index]);
        search(row, subset, max, index+1);

        subset.pop_back();
        search(row, subset, max, index+1);
    }
}

int getMaxProfit(vector<int> row) {
    int max = -1;
    vector<int> subset;
    search(row, subset, max, 0);    
    return max;
}

void solution(int testnum) {
    int max = -1;
    int size = (N-M+1)*N;
    int mod = N-M+1;
    vector<vector<int> > profits;

    // 1D dp table을 작성하여 sort하고 0, 1번째 index 참조하는 방법도 가능
    profits.assign(N, vector<int>(N-M+1, -1));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-M+1; j++) {
            profits[i][j] = getMaxProfit(vector<int>(honey[i].begin() + j, honey[i].begin() + j+M));
        }
    }

    for(int i=0; i<size; i++) {
        int row = (i / mod );
        int col = (i % mod );
        
        for(int j=0; j<size; j++) {
            int row2 = (j / mod) ;
            int col2 = (j % mod) ;
            if(row == row2) {
                // if(col2 >= col+M) {
                //     worker[1] = vector<int>(honey[row2].begin() + col2, honey[row2].begin() + col2+M);
                // } else {
                //     continue;
                // }
                continue;
            }

            int sum = profits[row][col] + profits[row2][col2];
            if(max < sum) {
                //printf("[update]\n row,col = %d,%d\n row2,col2 = %d,%d\n", row+1,col+1,row2+1,col+1);
                max = sum;
            }
        }
    }
    printf("#%d %d\n", testnum, max);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        getInput();
        solution(test_case);
	}
	return 0;
}