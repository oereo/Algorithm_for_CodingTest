//TODO 너무 하드코딩: 다시 풀어보기
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef struct Command {
    int face;
    bool is_clockwise;
} Command;
int n;
// U, D, F, B, L, R
vector<vector<string> > cube;
vector<Command> commands;
unordered_map<char, int> face = { {'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5} };
vector<vector<int> > adjacent_order = { {2, 4, 3 ,5}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {0, 2, 1, 3}, {0, 3, 1, 2} };

vector<string> createInitFace(char ch) {
    vector<string> face;
    string row = "";
    for(int i=0; i<3; i++) row += ch;

    face.assign(3, row);
    return face;
}

void getInput() {
    cin >> n;
    commands.assign(n, Command{0,0});
    for(int i=0; i<n; i++) {
        string com;
        cin >> com;
        commands[i].face = face[com[0]];
        commands[i].is_clockwise = (com[1] == '+' ? true:false);
    }

    cube.clear();
    cube.push_back(createInitFace('w'));
    cube.push_back(createInitFace('y'));
    cube.push_back(createInitFace('r'));
    cube.push_back(createInitFace('o'));
    cube.push_back(createInitFace('g'));
    cube.push_back(createInitFace('b'));
}

void rotateFace90(int face) {
    vector<string> temp;
    temp.assign(3, "000");

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            temp[j][2-i] = cube[face][i][j];
        }
    }
    cube[face] = temp;
}

void rotateFaceCounter90(int face) {
    vector<string> temp;
    temp.assign(3, "000");

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            temp[2-j][i] = cube[face][i][j];
        }
    }
    cube[face] = temp;
}

string getAffectedFaceRowState(int face, int rotated_face) {
    int changed_row = 0;
    string affected_row_state = "";

    for(int i=0; i<4; i++) {
        if(adjacent_order[face][i] == rotated_face) {
            changed_row = i;
            break;
        }
    }

    switch(changed_row) {
    case 0:
        for(int c=0; c<3; c++) {
            affected_row_state += cube[face][0][c];
        }
        break;
    case 1:
        for(int r=0; r<3; r++) {
            affected_row_state += cube[face][r][2];
        }
        break;
    case 2:
    for(int c=0; c<3; c++) {
            affected_row_state += cube[face][2][c];
        }
        break;
    case 3:
        for(int r=0; r<3; r++) {
            affected_row_state += cube[face][r][0];
        }
        break;
    }

    return affected_row_state;
}

string processAdjacentFaceRotateTopBottom(string prev_face_row, int face, int rotated_face) {
    vector<string> &changed_face_state = cube[face];
    string prev_row = "";
    int changed_row = 0;

    for(int i=0; i<4; i++) {
        if(adjacent_order[face][i] == rotated_face) {
            changed_row = i;
            break;
        }
    }

    switch(changed_row) {
    case 0:
        for(int c=0; c<3; c++) {
            prev_row += changed_face_state[0][c];
            changed_face_state[0][c] = prev_face_row[c];
        }
        break;
    case 1:
        for(int r=0; r<3; r++) {
            prev_row += changed_face_state[r][2];
            changed_face_state[r][2] = prev_face_row[r];
        }
        break;
    case 2:
    for(int c=0; c<3; c++) {
            prev_row += changed_face_state[2][c];
            changed_face_state[2][c] = prev_face_row[c];
        }
        break;
    case 3:
        for(int r=0; r<3; r++) {
            prev_row += changed_face_state[r][0];
            changed_face_state[r][0] = prev_face_row[r];
        }
        break;
    }

    return prev_row;
}

bool isFromOrToTop(int from, int to) {
    return from == 0 || to == 0;
}
bool isFromOrToBottom(int from, int to) {
    return from == 1 || to == 1;
}

string processTopCase(int from, int to, int rotated_face, string prev_row) {
    string next_row = "";

    if(from == 0) {
        switch (to)
        {
        case 2:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[2][i][0];
                    cube[2][i][0] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[2][i][2];
                    cube[2][i][2] = prev_row[2-i];
                }                
            }
            
            break;
        case 3:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[3][i][2];
                    cube[3][i][2] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[3][i][0];
                    cube[3][i][0] = prev_row[i];
                }                
            }            
            break;
        case 4:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[4][i][2];
                    cube[4][i][2] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[4][i][0];
                    cube[4][i][0] = prev_row[i];
                }                
            }
            break;
        case 5:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[5][i][0];
                    cube[5][i][0] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[5][i][2];
                    cube[5][i][2] = prev_row[2-i];
                }                
            }
            break;
        }
    }
    else if (to == 0) {
        switch (from)
        {
        case 2:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][i][2];
                    cube[0][i][2] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][i][0];
                    cube[0][i][0] = prev_row[2-i];
                }                
            }
            break;
        case 3:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][i][2];
                    cube[0][i][2] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][i][0];
                    cube[0][i][0] = prev_row[i];
                }                
            }            
            break;
        case 4:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][0][i];
                    cube[0][0][i] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][2][i];
                    cube[0][2][i] = prev_row[i];
                }                
            }
            break;
        case 5:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][0][i];
                    cube[0][0][i] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[0][2][i];
                    cube[0][2][i] = prev_row[2-i];
                }                
            }
            break;
        }
    }

    return next_row;
}

string processBottomCase(int from, int to, int rotated_face, string prev_row) {
    string next_row = "";

    if(from == 1) {
        switch (to)
        {
        case 2:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[2][i][0];
                    cube[2][i][0] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[2][i][2];
                    cube[2][i][2] = prev_row[i];
                }                
            }
            
            break;
        case 3:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[3][i][2];
                    cube[3][i][2] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[3][i][0];
                    cube[3][i][0] = prev_row[2-i];
                }                
            }            
            break;
        case 4:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[4][i][2];
                    cube[4][i][2] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[4][i][0];
                    cube[4][i][0] = prev_row[i];
                }                
            }
            break;
        case 5:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[5][i][0];
                    cube[5][i][0] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[5][i][2];
                    cube[5][i][2] = prev_row[2-i];
                }                
            }
            break;
        }
    }
    else if (to == 1) {
        switch (from)
        {
        case 2:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][i][0];
                    cube[1][i][0] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][i][2];
                    cube[1][i][2] = prev_row[i];
                }                
            }
            break;
        case 3:
            if(rotated_face == 4) {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][i][0];
                    cube[1][i][0] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][i][2];
                    cube[1][i][2] = prev_row[2-i];
                }                
            }            
            break;
        case 4:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][0][i];
                    cube[1][0][i] = prev_row[i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][2][i];
                    cube[1][2][i] = prev_row[i];
                }                
            }
            break;
        case 5:
            if(rotated_face == 2) {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][0][i];
                    cube[1][0][i] = prev_row[2-i];
                }
            }
            else {
                for(int i=0; i<3; i++) {
                    next_row += cube[1][2][i];
                    cube[1][2][i] = prev_row[2-i];
                }                
            }
            break;
        }
    }
    return next_row;
}

void printCube() {
    for(int c=0; c<6; c++) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout << cube[c][i][j];
            }
            cout <<endl;
        }
        cout <<endl;
    }
    cout << endl;
}

void solution() {
    for(int ord = 0; ord < n; ord++) {
        int rotated_face = commands[ord].face;
        bool is_clockwise = commands[ord].is_clockwise;
        int from = adjacent_order[rotated_face][0], to;
        
        string prev_row = getAffectedFaceRowState(adjacent_order[rotated_face][0], rotated_face);
        to = is_clockwise ? adjacent_order[rotated_face][1] : adjacent_order[rotated_face][3];
        is_clockwise ? rotateFace90(rotated_face) : rotateFaceCounter90(rotated_face);
        if (is_clockwise) {
            for(int i=0; i<3; i++) {
                // printCube();
                // printf("from = %d to = %d prev_row = %s\n", from, to, prev_row.c_str());
                if(isFromOrToTop(from, to)) {
                    prev_row = processTopCase(from, to, rotated_face, prev_row);
                }
                else if(isFromOrToBottom(from, to)) {
                    prev_row = processBottomCase(from, to, rotated_face, prev_row);
                }
                else {
                    prev_row = processAdjacentFaceRotateTopBottom(prev_row, adjacent_order[rotated_face][i+1], rotated_face);
                }

                from = to;
                to = adjacent_order[rotated_face][(i+2)%4];
            }
            // printCube();
            // printf("from = %d to = %d prev_row = %s\n", from, to, prev_row.c_str());
            if(isFromOrToTop(from, to)) {
                prev_row = processTopCase(from, to, rotated_face, prev_row);
            }
            else if(isFromOrToBottom(from, to)) {
                prev_row = processBottomCase(from, to, rotated_face, prev_row);
            }
            else {
                prev_row = processAdjacentFaceRotateTopBottom(prev_row, adjacent_order[rotated_face][0], rotated_face);
            }
        }
        else {
            for(int i=3; i>=0; i--) {
                // printCube();
                // printf("from = %d to = %d prev_row = %s\n", from, to, prev_row.c_str());
                if(isFromOrToTop(from, to)) {
                    prev_row = processTopCase(from, to, rotated_face, prev_row);
                }
                else if(isFromOrToBottom(from, to)) {
                    prev_row = processBottomCase(from, to, rotated_face, prev_row);
                }
                else {
                    prev_row = processAdjacentFaceRotateTopBottom(prev_row, adjacent_order[rotated_face][i], rotated_face);
                }

                from = to;
                to = adjacent_order[rotated_face][(i+3)%4];
            }
        }
        
    }   
}

void printResult() {
    for(int r=2; r>=0; r--) {
        for(int c=2; c>=0; c--) {
            cout << cube[0][r][c];
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        getInput();
        solution();
        printResult();
	}
	return 0;
}