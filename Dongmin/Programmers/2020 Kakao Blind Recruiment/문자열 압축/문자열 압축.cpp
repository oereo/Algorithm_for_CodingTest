#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();

    if(len == 1) return 1;
    else {
        char prev = 'A';
        int cnt = 0;
        for(int i=0; i<len; i++) {
            if(prev != s[i]) {
                prev=s[i];
                if(cnt==1) {
                    answer += 1;
                }
                else if(cnt>1) {
                    answer += (2 + (int)log10(cnt));
                }
                cnt=1;
            }
            else {
                cnt+=1;
            }
        }
        if(cnt==1) {
            answer += 1;
        }
        else if(cnt>1) {
            answer += (2 + (int)log10(cnt));
        }

        for(int l=2; l<=len/2; l++) {
            string prev = "AB";
            int cnt=0;
            int compressed_len=0;
            int quot = len/l, rem = len%l;
            int threshold = (rem==0)?quot:quot+1;

            for(int j=0; j<threshold; j++) {
                int start = j*l;
                string sub = (j!=threshold-1)?s.substr(start,l):s.substr(start);
                if(prev != sub) {
                    prev=sub;
                    if(cnt==1) {
                        compressed_len += l;
                    }
                    else if(cnt>1) {
                        compressed_len += (l+1 + (int)log10(cnt));
                    }
                    cnt=1;
                }
                else {
                    cnt+=1;
                }
            }

            if(rem==0) {
                if(cnt==1) {
                    compressed_len += l;
                }
                else if(cnt>1) {
                    compressed_len += (l+1 + (int)log10(cnt));
                }
            }
            else {
                compressed_len += rem;
            }

            if(answer>compressed_len) {
                answer = compressed_len;
            }
        }

    }

    return answer;
}