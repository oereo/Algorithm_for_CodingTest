#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int len = arrangement.size();
    int stick = 0;
    int new_stick = 0;
    int answer = 0;
    for(int i = 0; i < len; i++) {
        if(arrangement.substr(i,2) == "()"){
            answer += stick + new_stick;
            new_stick = 0;
            i++;
            continue;
        }
        if(arrangement[i] == '('){
            stick++;
            new_stick++;
        }
        else
            stick--;
    }
    
    return answer;
}
