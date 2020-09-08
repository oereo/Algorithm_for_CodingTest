#include <cstring>
#include <set>
#include <vector>
#include <string>
using namespace std;
enum PROCESS {DEL, ADD};
enum TYPE {COLUMN, BEAM};
typedef struct Structure{
    int x,y,type;
    bool operator<(const Structure &rhs) const {
        return x!=rhs.x ? x<rhs.x : (y!=rhs.y ? y<rhs.y : type<rhs.type);
    }
} Structure;
typedef struct CrossingInfo {
    int beam;
    int col;
} CrossingInfo;

CrossingInfo map[101][101];
int N;
void printMap() {
    for(int i=N; i>=0; i--) {
        for(int j=0; j<=N; j++) {
            printf("(%d %d)", map[i][j].col, map[i][j].beam);
        }
        printf("\n");
    }
    printf("\n");
}
bool canAddCol(int x, int y) {
    return (y==0) || (y>=1 && map[y-1][x].col) || (x>=1 && map[y][x-1].beam) || (map[y][x].beam);
}
bool canDelCol(int x, int y) {
    bool ret = true;
    if(x>=1 && map[y+1][x-1].beam) {
        ret &= map[y][x-1].col || (x>=2 && map[y+1][x-2].beam && map[y+1][x].beam);
    }

    if(map[y+1][x].beam) {
        ret &= (x+1<=N && map[y][x+1].col) || (x+1<=N && map[y+1][x+1].beam && x>=1 && map[y+1][x-1].beam);
    }

    if(map[y+1][x].col) {
        ret &= (x>=1 && map[y+1][x-1].beam) || (map[y+1][x].beam);
    }

    return ret;
}
bool canAddBeam(int x, int y) {
    return (y>=1 && map[y-1][x].col) || (y>=1 && map[y-1][x+1].col) || (x>=1 && map[y][x-1].beam && x+1<=N && map[y][x+1].beam);
}
bool canDelBeam(int x, int y) {
    bool ret = true;
    if(map[y][x].col) {
        ret &= (x>=1 && map[y][x-1].beam) || (y>=1 && map[y-1][x].col);
    }

    if(map[y][x+1].col) {
        ret &= (map[y][x+1].beam) || (y>=1 && map[y-1][x+1].col);
    }

    if(map[y][x-1].beam) {
        ret &= (y>=1 && map[y-1][x].col) || (y>=1 && x>=1 && map[y-1][x-1].col);
    }

    if(map[y][x+1].beam) {
        ret &= (x+2<=N && y>=1 && map[y-1][x+2].col) || (x+1<=N && y>=1 && map[y-1][x+1].col);
    }
    return ret;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int m = build_frame.size();
    N=n;
    memset(map, 0, sizeof(map));
    set<Structure> structures;         

    for(int i=0; i<m; i++) {
        int x=build_frame[i][0], y=build_frame[i][1];
        int type=build_frame[i][2], addDel=build_frame[i][3];

        if(type == TYPE::COLUMN) {
            if(addDel == PROCESS::ADD) {
                if(canAddCol(x,y)) {
                    structures.insert({x,y,type});
                    map[y][x].col = 1;
                }
            }
            else {
                if(canDelCol(x,y)) {
                    structures.erase({x,y,type});
                    map[y][x].col = 0;
                }
            }
        }
        else {
            if(addDel == PROCESS::ADD) {
                if(canAddBeam(x,y)) {
                    structures.insert({x,y,type});
                    map[y][x].beam = 1;
                }
            }
            else {
                if(canDelBeam(x,y)) {
                    structures.erase({x,y,type});
                    map[y][x].beam = 0;
                }
            }
        }

        printMap();
    }
    
    for(auto it=structures.begin(); it!=structures.end(); it++) {
        Structure st = *it;
        vector<int> vcst = {st.x, st.y, st.type};
        answer.push_back(vcst);
    }
    
    return answer;
}