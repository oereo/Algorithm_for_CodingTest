#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 공이 동시에 움직인다.
typedef struct Pos {
    int row, col;
} Pos;
typedef struct TiltEntry {
    int tiltnum;
    int dir;
    Pos redpos, bluepos;
    vector<string> board_state;
} TiltEntry;

int N, M;
vector<string> board;
Pos redball_pos, blueball_pos;
Pos goal_pos;

void printBoard(vector<string>& board_state) {
    for(int i=0; i<N; i++) {
        cout << board_state[i] << endl;
    }
    cout << endl;
}

void getInput() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string board_state_row;
        cin >> board_state_row;
        board.push_back(board_state_row);
        
        string::size_type red = board_state_row.find('R'), 
                          blue = board_state_row.find('B'),
                          goal = board_state_row.find('O');
        if(red != string::npos)  redball_pos = Pos{i, (int)red};
        if(blue != string::npos) blueball_pos = Pos{i, (int)blue};
        if(goal != string::npos) goal_pos = Pos{i, (int)goal}; 
    }
}

bool isSamePos(Pos pos1, Pos pos2) { return pos1.row == pos2.row && pos1.col == pos2.col; }
Pos getNewPosNotConsideringOtherBall(Pos ball_pos, int tilt_direction, vector<string>& board_state, bool& is_ball_goal) {
    Pos new_pos = ball_pos;
    enum DIRECTION { UP, DOWN, LEFT, RIGHT };

    switch(tilt_direction) {
    case DIRECTION::UP:
        for(int row = ball_pos.row - 1; row >= 0; row--) {
            if(board_state[row][ball_pos.col] == '#') {
                new_pos = {row+1, ball_pos.col};
                break;
            }
            else if(board_state[row][ball_pos.col] == 'O') {
                new_pos = {row, ball_pos.col};
                is_ball_goal = true;
                break;
            }
        }
        break;
    case DIRECTION::DOWN:
        for(int row = ball_pos.row + 1; row < N; row++) {
            if(board_state[row][ball_pos.col] == '#') {
                new_pos = {row-1, ball_pos.col};
                break;
            }
            else if(board_state[row][ball_pos.col] == 'O') {
                new_pos = {row, ball_pos.col};
                is_ball_goal = true;
                break;
            }
        }
        break;
    case DIRECTION::LEFT:
        for(int col = ball_pos.col - 1; col >= 0; col--) {
            if(board_state[ball_pos.row][col] == '#') {
                new_pos = {ball_pos.row, col+1};
                break;
            }
            else if(board_state[ball_pos.row][col] == 'O') {
                new_pos = {ball_pos.row, col};
                is_ball_goal = true;
                break;
            }
        }
        break;
    case DIRECTION::RIGHT:
        for(int col = ball_pos.col + 1; col < M; col++) {
            if(board_state[ball_pos.row][col] == '#') {
                new_pos = {ball_pos.row, col-1};
                break;
            }
            else if(board_state[ball_pos.row][col] == 'O') {
                new_pos = {ball_pos.row, col};
                is_ball_goal = true;
                break;
            }
        }
        break;
    }

    return new_pos;
}

void tiltBoard(int tilt_direction, vector<string>& board_state, Pos& redpos, Pos& bluepos) {
    enum DIRECTION { UP, DOWN, LEFT, RIGHT };
    Pos new_redpos, new_bluepos;
    bool is_red_goal = false, is_blue_goal = false;
    
    switch(tilt_direction) {
    case DIRECTION::UP:
        new_redpos = getNewPosNotConsideringOtherBall(redpos, tilt_direction, board_state, is_red_goal);
        new_bluepos = getNewPosNotConsideringOtherBall(bluepos, tilt_direction, board_state, is_blue_goal);
        if(isSamePos(new_redpos, new_bluepos) && !(is_red_goal && is_blue_goal)) {
            if(redpos.row < bluepos.row) {
                new_bluepos.row += 1;
            }
            else {
                new_redpos.row += 1;
            }
        }
        break;
    case DIRECTION::DOWN:
        new_redpos = getNewPosNotConsideringOtherBall(redpos, tilt_direction, board_state, is_red_goal);
        new_bluepos = getNewPosNotConsideringOtherBall(bluepos, tilt_direction, board_state, is_blue_goal);
        if(isSamePos(new_redpos, new_bluepos) && !(is_red_goal && is_blue_goal)) {
            if(redpos.row < bluepos.row) {
                new_redpos.row -= 1;
            }
            else {
                new_bluepos.row -= 1;
            }
        }
        break;
    case DIRECTION::LEFT:
        new_redpos = getNewPosNotConsideringOtherBall(redpos, tilt_direction, board_state, is_red_goal);
        new_bluepos = getNewPosNotConsideringOtherBall(bluepos, tilt_direction, board_state, is_blue_goal);
        if(isSamePos(new_redpos, new_bluepos) && !(is_red_goal && is_blue_goal)) {
            if(redpos.col < bluepos.col) {
                new_bluepos.col += 1;
            }
            else {
                new_redpos.col += 1;
            }
        }
        break;
    case DIRECTION::RIGHT:
        new_redpos = getNewPosNotConsideringOtherBall(redpos, tilt_direction, board_state, is_red_goal);
        new_bluepos = getNewPosNotConsideringOtherBall(bluepos, tilt_direction, board_state, is_blue_goal);
        if(isSamePos(new_redpos, new_bluepos) && !(is_red_goal && is_blue_goal)) {
            if(redpos.col < bluepos.col) {
                new_redpos.col -= 1;
            }
            else {
                new_bluepos.col -= 1;
            }
        }
        break;
    }

    board_state[redpos.row][redpos.col] = '.';
    board_state[bluepos.row][bluepos.col] = '.';
    redpos = new_redpos;
    bluepos = new_bluepos;
    board_state[redpos.row][redpos.col] = 'R';
    board_state[bluepos.row][bluepos.col] = 'B';
    board_state[goal_pos.row][goal_pos.col] = 'O';
}

void solution() {
    int ans = 11;

    queue<TiltEntry> q;
    for(int d=0; d<4; d++) {
        q.push({1,d,redball_pos, blueball_pos, board});
    }

    while(!q.empty()) {
        TiltEntry te = q.front();
        q.pop();
        if(te.tiltnum == 11) {
            ans = -1;
            break;
        }

        tiltBoard(te.dir, te.board_state, te.redpos, te.bluepos);
        // printf("tiltnum: %d\n", te.tiltnum);
        // printBoard(te.board_state);
        if(isSamePos(te.bluepos, goal_pos)) {
            continue;
        }
        else if(isSamePos(te.redpos, goal_pos)) {
            if(ans > te.tiltnum) {
                ans = te.tiltnum;
            }
            break;
        }

        for(int dir = 0; dir < 4; dir++) {
            if(dir != te.dir) {
                q.push({te.tiltnum+1, dir, te.redpos, te.bluepos, te.board_state});
            }
        }
    }

    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}