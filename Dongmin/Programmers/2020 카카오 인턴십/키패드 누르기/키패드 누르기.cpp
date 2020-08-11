#include <string>
#include <vector>
typedef struct Pos {
    int row,col;
}Pos;

using namespace std;
int getDistance(Pos hand, Pos pad) {
    return {abs(hand.row-pad.row)+abs(hand.col-pad.col)};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    Pos leftpos = {3,0};
    Pos rightpos = {3,2};

    for(int i=0; i<numbers.size(); i++) {
        int pad = numbers[i]==0?11:numbers[i];
        if(pad % 3 == 1) {
            leftpos = {pad/3,0};
            answer += "L";
        }
        else if(pad % 3 == 0) {
            rightpos = {pad/3-1,2};
            answer += "R";
        }
        else {
            Pos padpos = Pos{pad/3,1};
            int leftdist = getDistance(leftpos,padpos);
            int rightdist = getDistance(rightpos,padpos);

            if(leftdist < rightdist) {
                leftpos = padpos;
                answer += "L";
            }
            else if(rightdist < leftdist) {
                rightpos = padpos;
                answer += "R";
            }
            else {
                if(hand == "left") {
                    leftpos = padpos;
                    answer += "L";
                }
                else {
                    rightpos = padpos;
                    answer += "R";
                }
            }
        }
    }
    return answer;
}