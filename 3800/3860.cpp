#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N = 30;
const int MAX = MAX_N*MAX_N;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	while(1){
		int R, C;
		scanf("%d %d", &C, &R);
		if(R == 0) break;

		int G, H, N = R*C, E = (R-1)*MAX_N + C-1;
		bool wall[MAX] = {false,}, warp[MAX] = {false,};
		vector<P> adj[MAX];
		scanf("%d", &G);
		for(int i = 0; i < G; ++i){
			int r, c;
			scanf("%d %d", &c, &r);
			wall[r*MAX_N + c] = true;
		}
		scanf("%d", &H);
		for(int i = 0; i < H; ++i){
			int r1, c1, r2, c2, t;
			scanf("%d %d %d %d %d", &c1, &r1, &c2, &r2, &t);
			warp[r1*MAX_N + c1] = true;
			adj[r1*MAX_N + c1].push_back(P(r2*MAX_N + c2, t));
		}

		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				int curr = i*MAX_N + j;
				if(curr == E || wall[curr] || warp[curr]) continue;
				for(int d = 0; d < 4; ++d){
					int nr = i+roff[d], nc = j+coff[d], next = nr*MAX_N + nc;
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || wall[next]) continue;
					adj[curr].push_back(P(next, 1));
				}
			}
		}

		bool minusCycle = false;
		int dist[MAX];
		fill(dist, dist+MAX, INF);
		dist[0] = 0;
		for(int i = 0; i < MAX; ++i){
			for(int j = 0; j < MAX; ++j){
				if(dist[j] == INF) continue;
				for(auto &p: adj[j]){
					int next = p.first, d = dist[j] + p.second;
					if(dist[j] != INF && dist[next] > d){
						dist[next] = d;
						if(i == MAX-1) minusCycle = true;
					}
				}
			}
		}
		if(minusCycle) puts("Never");
		else if(dist[E] == INF) puts("Impossible");
		else printf("%d\n", dist[E]);
	}
}