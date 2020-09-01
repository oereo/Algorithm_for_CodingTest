#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    vector<int> lastPos;
    vector<int> bascket;

    for(int j=0; j<n; j++) {
        int i=0;
        for(; i<n; i++) {
            if(board[i][j]) {
                lastPos.push_back(i);
                break;
            }
        }
        if(i==n) {
            lastPos.push_back(n);
        }
    }

    for(int i=0; i<moves.size(); i++) {
        int col = moves[i]-1;
        if(lastPos[col] == n) {
            continue;
        }
        else {
            int selectedBlock = board[lastPos[col]++][col];
            if(bascket.size() != 0) {
                int top = bascket.back();
                if(selectedBlock == top) {
                    answer += 2;
                    bascket.pop_back();
                }
                else {
                    bascket.push_back(selectedBlock);
                }
            }
            else {
                bascket.push_back(selectedBlock);
            }
        }
    }
    return answer;
}