#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row;
    int col;
} Pos;
typedef struct microbeInfo{
    Pos pos;
    int size;
    int direction;
} microbeInfo;

int N,M,K;
vector<vector<int> > map;
Pos dirs[4];
vector<microbeInfo> microbes;

bool operator==(const Pos &a, const Pos &b) {
    return (a.row == b.row) && (a.col == b.col);
}
Pos operator+(const Pos &a, const Pos &b) {
    return {a.row + b.row, a.col + b.col};
}

void getInput() {
    cin >> N >> M >> K;
    microbes.assign(K, {{0,0},0,0});
    map.assign(N, vector<int>(N, -1));
    for(int i=1;i<N-1;i++) {
        for(int j=1;j<N-1;j++) {
            map[i][j] = 0;
        }
    }

    for(int i=0;i<K;i++) {
        cin >> microbes[i].pos.row >> microbes[i].pos.col >> microbes[i].size >> microbes[i].direction;
        map[microbes[i].pos.row][microbes[i].pos.col] = 1;
        //printf("microbes[%d]: pos=(%d,%d) size=%d direction=%d\n", i, microbes[i].pos.row, microbes[i].pos.col, microbes[i].size, microbes[i].direction);
    }

    dirs[0] = {-1,0};
    dirs[1] = {1,0};
    dirs[2] = {0,-1};
    dirs[3] = {0,1};
}

bool isValidPos(Pos& pos) {
    return pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < N;
}

void solution(int testnum) {
    for(int i=0; i<M; i++) {
        for(int j=0; j<microbes.size(); j++) {
            if(microbes[j].size > 0) {
                //printf("%dst microbe move (size:%d)\n", j, microbes[j].size);
                if(map[microbes[j].pos.row][microbes[j].pos.col] > 0) {
                    map[microbes[j].pos.row][microbes[j].pos.col] -= 1;
                }
                Pos newPos = microbes[j].pos + dirs[microbes[j].direction-1];
                microbes[j].pos.row = newPos.row;
                microbes[j].pos.col = newPos.col;
                //printf("newPos: (%d,%d)\n", newPos.row, newPos.col);

                if(map[newPos.row][newPos.col] == -1) {
                    microbes[j].size /= 2;
                    if(microbes[j].direction == 1) {
                        microbes[j].direction = 2;
                    } else if(microbes[j].direction == 2) {
                        microbes[j].direction = 1;
                    } else if(microbes[j].direction == 3) {
                        microbes[j].direction = 4;
                    } else {
                        microbes[j].direction = 3;
                    }
                } else {
                    map[newPos.row][newPos.col] += 1;
                }
            }

            // printf("===new map===\n");
            // for(int r=0;r<map.size();r++) {
            // for(int c=0;c<map[r].size();c++) {
            //         printf("%d ", map[r][c]);
            //     }
            //     printf("\n");
            // }
        }

        // 합쳐진 미생물 집단 처리
        for(int r=1; r<N-1; r++) {
            for(int c=1; c<N-1; c++) {
                if(map[r][c] > 1) {
                    //printf("map[r][c]=%d\n", map[r][c]);
                    vector<int> mergedMicrobes;
                    for(int k=0;k<microbes.size(); k++) {
                        //printf("microbes.pos = (%d,%d), (r,c) = (%d,%d)\n", microbes[k].pos.row, microbes[k].pos.col, r, c);
                        if(microbes[k].pos == Pos{r,c}) {
                            mergedMicrobes.push_back(k);
                        }
                    }

                    int max=mergedMicrobes[0];
                    for(int m=0;m<mergedMicrobes.size();m++) {
                        //printf("microbes[mergerMicrobes[m]].size=%d\n", microbes[mergedMicrobes[m]].size);
                        if(microbes[mergedMicrobes[m]].size > microbes[max].size) {
                            max = mergedMicrobes[m];
                        }
                    }
                    //printf("max idx=%d, max size=%d\n", max, microbes[max].size);
                    for(int m=0;m<mergedMicrobes.size();m++) {
                        if(mergedMicrobes[m] != max) {
                            microbes[max].size += microbes[mergedMicrobes[m]].size;
                            microbes[mergedMicrobes[m]].size = 0;
                        }
                    }
                    //printf("merged: total size=%d\n", microbes[max].size);
                    map[r][c] = 1;
                }
            }
        }

        // printf("===%d seconds after map===\n", i+1);
        // for(int r=0;r<map.size();r++) {
        //     for(int c=0;c<map[r].size();c++) {
        //         printf("%d ", map[r][c]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    int sum = 0;
    for(int i=0;i<microbes.size();i++) {
        sum += microbes[i].size;
    }
    
    printf("#%d %d\n", testnum, sum);
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