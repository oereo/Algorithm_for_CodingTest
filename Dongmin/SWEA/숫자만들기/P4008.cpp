#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> operators;
vector<int> numbers;

void getInput() {
    cin >> N;
    operators.assign(4, 0);
    numbers.assign(N, 0);
    for(int i=0;i<4;i++) {
        cin >> operators[i];
    }
    for(int i=0;i<N;i++) {
        cin >> numbers[i];
    }
}

void solution(int testnum) {
    vector<int> allCase;
    vector<int> opnum;
    for(int i=0; i<4; i++) {
        for(int j=0;j<operators[i];j++) {
            opnum.push_back(i);
        }
    }

    do {
        int result = numbers[0];
        for(int i=0; i<opnum.size(); i++) {
            if(opnum[i] == 0) {
                result += numbers[i+1];
            } 
            else if(opnum[i] == 1) {
                result -= numbers[i+1];
            }
            else if(opnum[i] == 2) {
                result *= numbers[i+1];
            }
            else {
                result /= numbers[i+1];
            }
        }
        allCase.push_back(result);
    }while(next_permutation(opnum.begin(), opnum.end()));

    int min = *min_element(allCase.begin(), allCase.end());
    int max = *max_element(allCase.begin(), allCase.end());

    printf("#%d %d\n", testnum, max - min);
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