/*
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 
노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 
베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

예:
genres	                                plays	                    return
[classic, pop, classic, classic, pop]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> cnt;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int>> tempv;

    for(int i = 0; i < genres.size(); i++){
        cnt[genres[i]] += plays[i];
    }

    map<string, int>::iterator i = cnt.begin();
    for(i = cnt.begin(); i != cnt.end(); ++i){
        tempv.push_back(make_pair(i->first, i->second));
    }

    /*
    for(int i = 0; i < genres.size(); i++){
        tempv.push_back(make_pair(genres[i], plays[i]));
    }
    */
    
    sort(tempv.begin(), tempv.end(), cmp);

    for(int i = 0; i < tempv.size(); i++){
        int big = 0, small = 0, bignum = 0, smallnum = 0;
        for(int j = 0; j < genres.size(); j++){
            if(tempv[i].first == genres[j]){
                if(plays[j] > big){
                    small = big;
					smallnum = bignum;
					big = plays[j];
					bignum = j;
				}
				else if (plays[j] > small) {
					small = plays[j];
					smallnum = j;
				}
			}
        }            
        answer.push_back(bignum);

		if (small > 0){
            answer.push_back(smallnum);
        }
    }
    
    return answer;
}