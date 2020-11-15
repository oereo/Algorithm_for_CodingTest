#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
typedef struct GearMove {
    int gear;
    int direction;
} GearMove;
int gear_state[4][8];
int K;
bool is_rotated[4] = {0,0,0,0};

void getInput() {
    for(int i=0; i<4; i++) {
        string state;
        cin >> state;
        for(int j=0; j<8; j++) {
            gear_state[i][j] = state[j] - '0';
        }
    }
    cin >> K;
}

void rotateGear(int gear, int direction) {
    if(direction == -1) {
        int changed = gear_state[gear][0];
        int temp;
        for(int i=7; i>=0; i--) {
            temp = gear_state[gear][i];
            gear_state[gear][i] = changed;
            changed = temp;
        }
    }
    else {
        int changed = gear_state[gear][7];
        int temp;
        for(int i=0; i<8; i++) {
            temp = gear_state[gear][i];
            gear_state[gear][i] = changed;
            changed = temp;
        }
    }
}

void rotateContinuously(queue<GearMove>& moved, bool touched_different[3]) {
    GearMove gm = moved.front();
    moved.pop();

    int left = gm.gear-1, right =gm.gear+1;
    int opposite = (gm.direction == 1 ? -1 : 1);
    if(left >= 0 && touched_different[left] && !is_rotated[left]) {
        rotateGear(left, opposite);
        is_rotated[left] = true;
        moved.push({left, opposite});
    }
    if(right < 4 && touched_different[gm.gear] && !is_rotated[right]) {
        rotateGear(right, opposite);
        is_rotated[right] = true;
        moved.push({right, opposite});
    }
}

void solution() {
    int ans = 0;
    int rotated_gear, direction;
    for(int i=0; i<K; i++) {
        memset(is_rotated, 0, sizeof(is_rotated));
        bool touched_different[3] = {0,0,0};
        for(int j=0; j<3; j++) {
            touched_different[j] = (gear_state[j][2] != gear_state[j+1][6]);
        }

        cin >> rotated_gear >> direction;
        rotateGear(rotated_gear-1, direction);
        is_rotated[rotated_gear-1] = true;

        queue<GearMove> q;
        q.push({rotated_gear-1, direction});
        while(q.size() != 0) {
            rotateContinuously(q, touched_different);
        }
    }

    for(int i=0; i<4; i++) {
        ans += gear_state[i][0] * pow(2, i);
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
    return 0;
}