#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001;

int M, N;
vector<vector<int> > subjects;
vector<vector<int> > pres;
int semester[MAXN];
bool is_taken[MAXN];
queue<int> qu;


void getInput() {
    cin >> N >> M;
    subjects.assign(MAXN, vector<int>());
    pres.assign(MAXN, vector<int>());
    int in_degree[MAXN];

    memset(in_degree, 0, sizeof(in_degree));
    memset(is_taken, 0, sizeof(is_taken));

    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        subjects[A].push_back(B);
        pres[B].push_back(A);
        in_degree[B] += 1;
    }

    for (int i=1; i<=N; i++) {
        if (in_degree[i] == 0) {
            qu.push(i);
        }
    }
}

bool isTakenAllPrerequisites(int sub) {
    for (int i=0; i<pres[sub].size(); i++) {
        int pre = pres[sub][i];
        if (!is_taken[pre]) return false;
    }
    return true;
}

void solution() {
    int qu_size = qu.size();
    int sem = 1;

    while (!qu.empty()) {
        int sub = qu.front();

        qu.pop();
        qu_size -= 1;
        is_taken[sub] = 1;
        semester[sub] = sem;

        for (int i=0; i<subjects[sub].size(); i++) {
            int pushed = subjects[sub][i];
            if (isTakenAllPrerequisites(pushed)) { 
                qu.push(pushed);
            }
        }

        if (qu_size == 0) {
            qu_size = qu.size();
            sem += 1;
        }
    }

   
   for (int i=1; i<=N; i++) {
       cout << semester[i] << " ";
   }
}

int main() {
    getInput();
    solution();
}