#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N,K;
string numstr;

void getInput() {
    cin >> N >> K;
    cin >> numstr;
}

int stoh(string str) {
    int base=1,ret=0;
    for(int i=str.size()-1; i>=0; i--,base*=16) {
        if(isalpha(str[i])) {
            ret += (10 + str[i] - 'A')*base;
        }
        else {
            ret += (str[i]-'0')*base;
        }
    }
    return ret;
}

void solution(int testnum) {
    int ans=0;
    int len = N/4, bound = 0;
    vector<vector<string> > numset;
    numset.assign(N/4, vector<string>());

    for(int i=0; i<4; i++) {
        numset[0].push_back(numstr.substr(bound,len));
        bound += len;
    }

    for(int i=1; i<numset.size(); i++) {
        bound = 0;
        char temp = numstr.back();
        numstr.pop_back();
        numstr.insert(numstr.begin(), temp);
        for(int j=0; j<4; j++) {
            numset[i].push_back(numstr.substr(bound,len));
            bound += len;
        }
    }

    set<int, greater<int> > decset;
    for(int i=0; i<N/4; i++) {
        for(int j=0; j<4; j++) {
            decset.insert(stoh(numset[i][j]));
        }
    }

    int idx=0;
    for(auto it=decset.begin(); it!=decset.end(); it++) {
        if(idx == K-1) {
            ans = *it;
            break;
        }
        idx++;
    }

    printf("#%d %d\n", testnum, ans);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        getInput();
        solution(test_case);
	}
	return 0;
}