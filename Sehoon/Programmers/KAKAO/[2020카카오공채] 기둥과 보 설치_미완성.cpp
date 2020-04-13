#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> temp;
    vector<vector<int>> map;
    int a = 0;
    int length = build_frame.size();
    //cout << length;
    map.assign(2*n, vector<int>(2*n,0));
    
    
    for(int i = 0; i<length; i++){
        //for(int j = 0; j<4; j++){
            if(build_frame[i][2] == 0){
                if(build_frame[i][3] == 1){
                    if(build_frame[i][1] == 0 || (build_frame[i][0] >0 && map[build_frame[i][1]][build_frame[i][0]] ==1) ){
                       map[build_frame[i][1]][build_frame[i][0]] = 1;
                       map[build_frame[i][1]+1][build_frame[i][0]] = 1;
                        temp.push_back(build_frame[i][0]);
                        temp.push_back(build_frame[i][1]);
                        temp.push_back(0);
                        answer.push_back(temp);
                        temp.clear();
                    }
                    
                }
                if(build_frame[i][3] == 0 && map[build_frame[i][1]][build_frame[i][0]] == 1){
                    //map[build_frame[i][1]+1][build_frame[i][0]] = 0;
                    map[build_frame[i][1]][build_frame[i][0]] = 0;
                    //answer[1].erase();
                }
            }
            else if(build_frame[i][2] == 1){
                 if(build_frame[i][3] == 1){
                     map[build_frame[i][1]][build_frame[i][0]] = 1;
                     map[build_frame[i][1]][build_frame[i][0]+1] = 1;
                        temp.push_back(build_frame[i][0]);
                        temp.push_back(build_frame[i][1]);
                        temp.push_back(1);
                        answer.push_back(temp);
                        temp.clear();
                 }
                 if(build_frame[i][3] == 0 && map[build_frame[i][1]][build_frame[i][0]] == 1&& map[build_frame[i][1]][build_frame[i][0]+1] != 1){
                    //map[build_frame[i][1]+1][build_frame[i][0]] = 0;
                    map[build_frame[i][1]][build_frame[i][0]] = 0;
                    
                }
                
            }
        //}
    }
    
    for(int i = 0; i<answer.size(); i++){
        for(int j = 0; j<answer.size(); j++){
            sort(answer.begin(), answer.end());
            }
    }
    
    for(int i = 0; i<map.size(); i++){
        for(int j = 0; j<map.size(); j++){
            if(map[j][i] == 1){
                //answer.push_back(j);
            }
            
            cout << map[j][i];
        }
        cout << endl;
    }
    
    return answer;
}