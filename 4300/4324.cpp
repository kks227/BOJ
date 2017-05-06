#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N < 0) break;

		int E[100], dist[100];
		vector<int> adj[100];
		bool reachable[100][100] = {0};
		for(int i=0; i<N; i++){
			int S;
			scanf("%d %d", E+i, &S);
			for(int j=0; j<S; j++){
				int k;
				scanf("%d", &k);
				adj[i].push_back(k-1);
				reachable[i][k-1] = true;
			}
			reachable[i][i] = true;
		}
		for(int k=0; k<N; k++)
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					reachable[i][j] |= reachable[i][k] && reachable[k][j];

		bool mcycle[100] = {0};
		fill(dist, dist+N, INF);
		dist[0] = -100;
		for(int k=0; k<N; k++){
			for(int i=0; i<N; i++){
				for(int j: adj[i]){
					int nd = dist[i] - E[j];
					if(0 > nd && dist[j] > nd){
						dist[j] = nd;
						if(k == N-1) mcycle[j] = true;
					}
				}
			}
		}
		bool result = (dist[N-1] < INF);
		for(int i=0; i<N; i++)
			if(mcycle[i] && reachable[i][N-1]) result = true;
		puts(result ? "winnable" : "hopeless");
	}
}