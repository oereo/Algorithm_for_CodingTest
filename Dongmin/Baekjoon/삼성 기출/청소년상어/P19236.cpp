#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 4;

typedef struct FishInfo {
    int number;
    int direction;
} FishInfo;
typedef struct Pos {
    int row;
    int col;
} Pos;

int maxSum = 0;
Pos sharkPos = Pos{1,1};
Pos dir[8] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
vector<vector<FishInfo> > map;
vector<Pos> fishes;
bool operator==(const Pos& a, const Pos& b) {
    return (a.row == b.row && a.col == b.col);
}
bool operator!=(const Pos& a, const Pos& b) {
    return !(a==b);
}
Pos operator+(const Pos& a, const Pos& b) {
    return Pos{a.row + b.row, a.col + b.col};
}
Pos operator*(const Pos&a, const int b) {
    return Pos{a.row * b, a.col * b};
}

bool isValidPos(Pos &pos) {
    return (pos.row >= 1 && pos.row <=4 && pos.col >=1 && pos.col <= 4);
}

void getInput() {
    fishes.assign(SIZE*SIZE+1, {-1,-1});
    map.assign(SIZE+2, vector<FishInfo>(SIZE+2, {-1,-1}));
    for(int i=1;i<=SIZE;i++) {
        for(int j=1;j<=SIZE;j++){
            cin >> map[i][j].number >> map[i][j].direction;
            fishes[map[i][j].number] = {i,j};
        }
    }
}

void printMap() {
    for(int i=0;i<SIZE+2;i++) {
        for(int j=0;j<SIZE+2;j++) {
            printf("(%d, %d) ", map[i][j].number, map[i][j].direction);
        }
        printf("\n");
    }
}

void fishMove() {
    for(int i=1; i<=16; i++) {
        bool fail = true;
        bool isOriginDir = false;
        int originDir, newDir;

        do {
            if(fishes[i] != Pos{-1,-1}) {
                originDir = map[fishes[i].row][fishes[i].col].direction;
                newDir = originDir;

                Pos originPos = fishes[i];
                Pos newPos = fishes[i] + dir[newDir - 1];
                if(newPos != sharkPos && map[newPos.row][newPos.col].number != -1) {
                    FishInfo changedFish = map[newPos.row][newPos.col];
                    FishInfo changingFish = map[fishes[i].row][fishes[i].col];

                    fishes[changedFish.number] = fishes[i];
                    fishes[i] = newPos;
                    map[newPos.row][newPos.col] = changingFish;
                    map[originPos.row][originPos.col] = changedFish;
                    fail = false;
                } else {
                    newDir = (newDir % 8) + 1;
                    map[originPos.row][originPos.col].direction = newDir;
                }

                isOriginDir = (originDir == newDir);
            } else {
                fail = false;
            }
        } while(fail && !isOriginDir);
    }
}

void dfs(Pos shark, int& sum) {
    vector<vector<FishInfo> > mapTemp = map;
    vector<Pos> fishesTemp = fishes;
    Pos sharkPosTemp = sharkPos;
    int eatenFish = map[shark.row][shark.col].number;

    sum += eatenFish;
    if(sum > maxSum) {
        maxSum = sum;
    }
    map[shark.row][shark.col].number = 0;
    sharkPos = shark;
    //printf("shark position: (%d, %d)\n",sharkPos.row, sharkPos.col);

    fishes[eatenFish]= {-1,-1};
    //printf("============ before fishMove =============\n");
    //printMap();
    fishMove();
    //printf("============ after fishMove ==============\n");
    //printMap();
    
    int i=1;
    Pos sharkNewPos = sharkPos + (dir[map[sharkPos.row][sharkPos.col].direction-1] * i);
    for(; isValidPos(sharkNewPos); sharkNewPos = sharkPos + (dir[map[sharkPos.row][sharkPos.col].direction-1] * (++i))){
        //printf("shark new position: (%d, %d)\n", sharkNewPos.row, sharkNewPos.col);
        if(map[sharkNewPos.row][sharkNewPos.col].number != 0) { 
            dfs(sharkNewPos, sum);
        }
    }

    // 복구
    map = mapTemp;
    fishes = fishesTemp;
    sharkPos = sharkPosTemp;
    sum -= eatenFish;
}

void solution() {
    int sum = 0;
    dfs(Pos{1,1}, sum);
}

int main() {
    getInput();
    solution();
    printf("%d", maxSum);

    return 0;
}