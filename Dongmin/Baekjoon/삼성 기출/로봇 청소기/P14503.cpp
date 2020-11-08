#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row, col;
} Pos;
typedef struct RobotCleaner {
    Pos pos;
    int direction;
} RobotCleaner;

int N,M;
RobotCleaner robot_cleaner;
vector<vector<int> > room;
vector<vector<bool> > is_cleaned;
int move_direction[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void getInput() {
    cin >> N >> M;
    cin >> robot_cleaner.pos.row >> robot_cleaner.pos.col >> robot_cleaner.direction;
    room.assign(N, vector<int>(M, 0));
    is_cleaned.assign(N, vector<bool>(M, false));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> room[i][j];
        }
    }
}

void cleanSlot(int& clean_slot_num) {
    clean_slot_num += 1;
}
bool isWall(Pos& pos) {
    return room[pos.row][pos.col] == 1;
}
bool canCleanLeft(Pos &left_pos) {
    return room[left_pos.row][left_pos.col] == 0 && is_cleaned[left_pos.row][left_pos.col] == false;
}

void cleanRoom(int& clean_slot_num) {
    bool is_search_step = false; 
    int wall_or_cleaned_num = 0;
    while(true) {
        if(!is_search_step){
            cleanSlot(clean_slot_num);
            is_cleaned[robot_cleaner.pos.row][robot_cleaner.pos.col] = true;

        }
        
        int &robot_direction = robot_cleaner.direction;
        robot_direction -= 1;
        if(robot_direction < 0) robot_direction += 4;
        Pos left_pos = { robot_cleaner.pos.row + move_direction[robot_direction][0],
                         robot_cleaner.pos.col + move_direction[robot_direction][1] };

        if(canCleanLeft(left_pos)) {
            robot_cleaner.pos = left_pos;
            is_search_step = false;
            wall_or_cleaned_num = 0;
        }
        else if(wall_or_cleaned_num < 3) {
            is_search_step = true;
            wall_or_cleaned_num += 1;
        }
        else {
            int opposite_direction = (robot_direction + 2) % 4;
            Pos back_pos = { robot_cleaner.pos.row + move_direction[opposite_direction][0],
                             robot_cleaner.pos.col + move_direction[opposite_direction][1] };
            if(!isWall(back_pos)) {
                robot_cleaner.pos = back_pos;
                is_search_step = true;
                wall_or_cleaned_num = 0;
            }
            else {
                break;
            }
        }
    }
}

void solution() {
    int ans = 0;
    cleanRoom(ans);
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}