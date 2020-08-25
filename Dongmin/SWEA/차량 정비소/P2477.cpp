#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct Client {
	int n,a,b;
	int enda, endb;
} Client;

struct cmpa {
	bool operator()(Client t, Client u) {
		return t.enda!=u.enda? t.enda>u.enda : t.a>u.a;
	}
};
struct cmpb {
	bool operator()(Client t, Client u) {
		return t.endb!=u.endb? t.endb>u.endb : t.b>u.b;
	}
};

int ans;
int N,M,K,A,B;
int ai[10], bj[10], tk[1001];
bool av[10], bv[10];
queue<int> awq;
priority_queue<Client,vector<Client>,cmpa> auq;
priority_queue<Client,vector<Client>,cmpa> bwq;
priority_queue<Client,vector<Client>,cmpb> buq;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
		ans=0;
		cin >> N >> M >> K >> A >> B;
        for(int i=1; i<=N; i++) cin>>ai[i];
		for(int j=1; j<=M; j++) cin>>bj[j];
		for(int k=1; k<=K; k++) cin>>tk[k];
		memset(av, 0, sizeof(av)); memset(bv, 0, sizeof(bv));
		int minN=1, minM=1;
		int completed = 0;

		for(int t=0, k=1; completed!=K; t++) {
			while(!buq.empty()) {
				Client buc = buq.top();
				if(buc.endb == t) {
					buq.pop();
					bv[buc.b] = 0;
					//printf("#%d completed a=%d, b=%d\n", buc.n, buc.a, buc.b);
					if(buc.a == A && buc.b == B) {
						ans += buc.n;
					}
					minM = min(buc.b, minM);
					completed += 1;
				}
				else break;
			}

			while(!bwq.empty()) {
				Client bwc = bwq.top();
				if(buq.size() < M) {
					bwq.pop();
					bwc.b = minM;
					bwc.endb = t + bj[minM];
					buq.push(bwc);
					bv[minM] = 1;
					//printf("waiting b #%d into  using b #%d\n", bwc.n, bwc.b);

					int i=1;
					for(;i<=M; i++){
						if(!bv[i]){
							minM = i;
							break;
						}
					}
					if(i==M+1) minM=M+1;
				}
				else break;
			}

			while(!auq.empty()) {
				Client auc = auq.top();
				if(auc.enda == t) {
					auq.pop();
					av[auc.a] = 0;
					minN = min(auc.a, minN);
					

					if(buq.size() < M) {
						auc.b = minM;
						auc.endb = t + bj[minM];
						buq.push(auc);
						bv[auc.b] = 1;
						//printf("using a #%d into using b #%d\n", auc.n, auc.b);

						int i=1;
						for(;i<=M; i++){
							if(!bv[i]){
								minM = i;
								break;
							}
						}
						if(i==M+1) minM=M+1;
					}
					else {
						bwq.push(auc);
						//printf("using a #%d into waiting b\n", auc.n);
					}
				}
				else break;
			}

			while(!awq.empty()) {
				int awc = awq.front();
				if(auq.size() < N) {
					awq.pop();
					auq.push(Client{awc,minN,0,t+ai[minN],0});
					av[minN] = 1;
					//printf("waiting a #%d into using a %d\n", awc, minN);

					int i=1;
					for(;i<=N; i++){
						if(!av[i]){
							minN = i;
							break;
						}
					}
					if(i==N+1) minN=N+1;
				}
				else break;
			}

			while(true) {
				if(tk[k] == t && k <= K) {
					if(auq.size() == N) {
						awq.push(k);
						//printf("new #%d into waiting a\n", k);
					}
					else {
						auq.push(Client{k, minN, 0, t+ai[minN], 0});
						av[minN] = 1;
						//printf("new #%d into using a %d\n", k, minN);

						int i=1;
						for(;i<=N; i++){
							if(!av[i]){
								minN = i;
								break;
							}
						}
						if(i==N+1) minN=N+1;
					}
					k++;
				}
				else break;
			}
			//printf("#%d sec: minN=%d\n", t, minN);
		}
		
		if(ans==0) ans=-1;
		printf("#%d %d\n", test_case, ans);
	}
	
	return 0;
}