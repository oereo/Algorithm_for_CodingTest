#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef struct Pos {
    int row, col;
} Pos;
typedef struct CCTV {
    int type;
    Pos pos;
} CCTV;

int N, M;
int office[9][9];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
vector<vector<int> > cctv_dir = { {0}, {0}, {0,2}, {0,3}, {0,2,3}, {0,1,2,3} };
int dir_case[6] = {-1, 4, 2, 4, 4, 1};
vector<CCTV> cctvs;

void getInput() {
    memset(office, -1, sizeof(office));
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6) {
                cctvs.push_back({office[i][j], {i,j}});
            }
        }
    }
}

bool isValidPos(Pos &pos) {
    return pos.row >= 0 && pos.row < N && pos.col >=0 && pos.col < M;
}

void markMonitored(Pos pos, int direction) {
    for(int i=1; ; i++){
        Pos monitored_pos = {pos.row + dir[direction][0]*i, pos.col + dir[direction][1]*i};
        if(isValidPos(monitored_pos)) {
            int& monitored_state = office[monitored_pos.row][monitored_pos.col];
            if(monitored_state == 0) {
                monitored_state = 7;
            }
            else if(monitored_state == 6) {
                break;
            }
        }
        else {
            break;
        }
    }
}

void printOffice() {
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++) {
            cout << office[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void setCCTVDirection(int order, vector<int>& rotate_num, int& min_blind) {
    if(order == cctvs.size()-1) {
        int office_cpy[9][9];
        memcpy(office_cpy, office, sizeof(office));

        for(int i=0; i<cctvs.size(); i++) {
            int cctv_type = cctvs[i].type;
            vector<int> monitor_direction = cctv_dir[cctv_type];
            int rotated90n = rotate_num[i];

            for(int j=0; j<monitor_direction.size(); j++) {
                int rotated_direction = (monitor_direction[j] + rotated90n) % 4;
                Pos cctv_pos = cctvs[i].pos;
                markMonitored(cctv_pos, rotated_direction);
            }
        }

        int blind_spots = 0;
        for(int r=0; r<N; r++) {
            for(int c=0; c<M; c++) {
                if(office[r][c] == 0) {
                    blind_spots += 1;
                }
            }
        }

        if(min_blind > blind_spots) {
            min_blind = blind_spots;
        }

        memcpy(office, office_cpy, sizeof(office));
    }
    else {
        int cctv_type = cctvs[order+1].type;
        for(int i=0; i<dir_case[cctv_type]; i++) {
            rotate_num.push_back(i);
            setCCTVDirection(order+1, rotate_num, min_blind);
            rotate_num.pop_back();
        }
    }
}

void solution() {
    int ans = 98765432;
    // 조건 더 꼼꼼히 체크: cctv가 없을 수도 있음
    if(cctvs.size() == 0) {
        int blind_spots = 0;
        for(int r=0; r<N; r++) {
            for(int c=0; c<M; c++) {
                if(office[r][c] == 0) {
                    blind_spots += 1;
                }
            }
        }
        printf("%d", blind_spots);
        return;
    }
    vector<int> rotate_num;

    int cctv_type = cctvs[0].type;
    for(int i=0; i<dir_case[cctv_type]; i++) {
        rotate_num.push_back(i);
        setCCTVDirection(0, rotate_num, ans);
        rotate_num.pop_back();
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
    return 0;
}