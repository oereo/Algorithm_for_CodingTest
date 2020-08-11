#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int D, W, K;
vector<vector<int> > film;
vector<bool> dosed;

void getInput() {
    cin >> D >> W >> K;
    film.assign(D, vector<int>(W, 0));
    dosed.assign(D, false);
    for(int i=0; i<D; i++) {
        for(int j=0; j<W; j++) {
            cin >> film[i][j];
        }
    }
}

bool isPassed() {
    bool ret = true;
    int connCellType = 0;
    int connCellNum = 0;

    for(int i=0; i<W; i++) {
        bool isPassedLayer = false;
        for(int j=0; j<D; j++) {
            if(film[j][i]==connCellType) {
                connCellNum += 1;
            }
            else {
                connCellNum = 1;
                if(D-j<K-1) {
                    break;
                }
                connCellType = connCellType==0?1:0;
            }

            if(connCellNum == K) {
                isPassedLayer = true;
                connCellNum = 0;
                break;
            }
        }

        if(!isPassedLayer) {
            ret = false;
            break;
        }
    }

    return ret;
}

void dfs(int cnt, int layer, int& min) {
    if(cnt>=min || cnt>D || layer>D) {
        return;
    }

    if(isPassed()) {
        if(min>cnt) {
            min=cnt;
        }
    }
    else {
        if(layer>=D) return;
        dfs(cnt,layer+1,min);

        vector<int> temp;
        temp.assign(W, 0);
        for(int i=0; i<W; i++) {
            temp[i] = film[layer][i];
            film[layer][i] = 0;
        }
        dfs(cnt+1,layer+1,min);

        for(int i=0; i<W; i++) {
            film[layer][i] = 1;
        }
        dfs(cnt+1,layer+1,min);

        for(int i=0; i<W; i++) {
            film[layer][i] = temp[i];
        }
    }
}

void solution(int testnum) {
    int minDos=D;
    dfs(0,0,minDos);
    printf("#%d %d\n", testnum, minDos);
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