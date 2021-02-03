#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int graph[201][201];
int d[201][201];
const int MAX = 10000000;
// 200 * 200 * 200 = 8,000,000
void floyd(int n)
{
	for (int m = 1; m <= n; m++) 
		for (int s = 1; s <= n; s++) 
			for (int e = 1; e <= n; e++)
				if (d[s][e] > d[s][m] + d[m][e])
					d[s][e] = d[s][m] + d[m][e];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    memset(graph,0,sizeof(graph));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            graph[i][j] = MAX;
        }
    }

    for (int i=0; i<fares.size(); i++) {
        int d=fares[i][0];
        int c=fares[i][1];
        int f=fares[i][2];

        graph[d][c] = f;
        graph[c][d] = f;
    }

    memcpy(d, graph, sizeof(graph));
    floyd(n);
    
    int min_fare = MAX;
    for (int m=1; m<=n; m++) {
        if (d[s][m] == MAX) continue;
        int together = d[s][m];

        int toA = d[m][a];
        int toB = d[m][b];
        if (toA == MAX || toB == MAX) continue;
        int total = together + toA + toB;
        if (min_fare > total) min_fare = total;
    }

    return min_fare;
}