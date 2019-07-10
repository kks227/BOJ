#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 12;
const int MAX_D = 8;
typedef tuple<int, int, int> Edge;

int main(){
	int N, D, M, k[MAX][MAX_D+1];
	vector<Edge> adj[MAX][MAX_D];
	scanf("%d %d %d", &N, &D, &M);
	for(int i = 0; i < M; ++i){
		int u, v, d, c;
		scanf("%d %d %d %d", &u, &v, &d, &c);
		adj[u-1][d-1].push_back(Edge(v-1, c, 0));
	}
	for(int i = 0; i < N*D; ++i){
		int u, d, w;
		scanf("%d %d %d", &u, &d, &w);
		k[u-1][d-1] = w;
	}

	for(int d = 0; d < D; ++d){
		while(1){
			bool noChange = true, isFull = true;
			for(int i = 0; i < N; ++i){
				for(auto &e: adj[i][d]){
					int j, c, dummy;
					tie(j, c, dummy) = e;
					int &f = get<2>(e);
					if(c == f) continue;
					
					int temp = min(k[i][d], c-f);
					if(temp > 0){
						noChange = false;
						k[i][d] -= temp;
						k[j][d+1] += temp;
						f += temp;
					}
					if(c > f) isFull = false;
				}
			}

			if(isFull) break;
			if(noChange){
				puts("suboptimal");
				return 0;
			}
		}
		for(int i = 0; i < N; ++i)
			k[i][d+1] += k[i][d];
	}
	puts("optimal");
}