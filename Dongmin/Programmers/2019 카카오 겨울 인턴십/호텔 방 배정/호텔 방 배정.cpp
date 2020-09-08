#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    map<long long, int> required_room;
    map<long long, int> room_map;
    vector<long long> sorted_room = room_number;
    int n = sorted_room.size();

    // O(nlgn)
    sort(sorted_room.begin(), sorted_room.end());

    // O(n)
    for(int i=0; i<n; i++) {
        long long number = sorted_room[i];
        if(!required_room.count(number)){
            required_room[number] = 1;
        }
        else {
            required_room[number] += 1;
        }
    }

    // O(n)
    for(auto it=required_room.begin(); it!=required_room.end(); it++) {
        long long room = (*it).first;
        int required = (*it).second;

        long long prev_max;
        if(!room_map.count(room)) {
            prev_max = room + required;
            for(int i=0; i<required; i++) {
                room_map[room + i] = 1;
            }
        }
        else {
            for(int i=0; i<required; i++) {
                room_map[prev_max + i] = 1;
            }
            prev_max += required;
        }
    }

    // O(nlgn)
    for(int i=0; i<n; i++) {
        auto it = room_map.lower_bound(room_number[i]);
        long long room_num = (*it).first;
        answer.push_back(room_num);
        room_map.erase(room_num);
    }
    return answer;
}