// 문제 설명
// Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 빨간색으로 칠해져 있고 모서리는 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

// image.png

// Leo는 집으로 돌아와서 아까 본 카펫의 빨간색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

// Leo가 본 카펫에서 갈색 격자의 수 brown, 빨간색 격자의 수 red가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
// 빨간색 격자의 수 red는 1 이상 2,000,000 이하인 자연수입니다.
// 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
// 입출력 예
// brown	red	return
// 10	2	[4, 3]
// 8	1	[3, 3]
// 24	24	[8, 6]

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    vector<int> answer1;
    vector<int> aaa;
    
    for(int i = 1; i<=red; i++){
        if(red%i == 0){
            aaa.push_back((red/i)); 
        }  
    }
    for(int i = 0; i<aaa.size();i++){
        cout << aaa[i];
        if((aaa[i]*2)+(aaa[aaa.size()-1-i]*2)+4 == brown){
            int maxcnt = max(aaa[i], aaa[aaa.size()-1-i]);
            int mincnt = min(aaa[i], aaa[aaa.size()-1-i]);
            //cout << maxcnt;
            answer1.push_back(maxcnt+2);
            answer1.push_back(mincnt+2);
            
        }
    }
    answer.push_back(answer1[0]);
    answer.push_back(answer1[1]);
    //for(int i = 0; i<answer.size(); i++){
    //    s.insert(answer[i]);
    //}
    //answer = s;
    
    return answer;
}