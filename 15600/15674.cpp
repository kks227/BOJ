#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 200000;

int main(){
	int N, D, Q, G = 0, c[2][MAX], gn[MAX];
	bool gSide[MAX];
	long long gCost[2][MAX][2] = {0}; // sum of: tree sort, group number, group side
	vector<int> gMem[MAX][2];
	vector<P> adj[MAX];
	scanf("%d %d", &N, &D);
	for(int i=0; i<N; i++){
		scanf("%d %d", &c[0][i], &c[1][i]);
		gn[i] = -1;
	}
	for(int i=0; i<D; i++){
		int c, u, v;
		scanf("%d %d %d", &c, &u, &v);
		u--; v--;
		adj[u].push_back(P(v, c));
		adj[v].push_back(P(u, c));
	}

	bool visited[MAX] = {0};
	for(int i=0; i<N; i++){
		if(visited[i]) continue;

		visited[i] = true;
		queue<P> Q;
		Q.push(P(i, 0));
		gn[i] = G;
		gSide[i] = false;
		gMem[G][0].push_back(i);

		while(!Q.empty()){
			P temp = Q.front(); Q.pop();
			int curr = temp.first;
			bool side = !!temp.second;

			for(auto& e: adj[curr]){
				int next = e.first;
				if(visited[next]) continue;

				visited[next] = true;
				bool nSide = side;
				if(e.second == 1) nSide = !nSide;
				Q.push(P(next, nSide));
				gn[next] = G;
				gSide[next] = nSide;
				gMem[G][nSide].push_back(next);
			}
		}

		for(int a: gMem[G][0]){
			gCost[0][G][0] += c[0][a];
			gCost[1][G][0] += c[1][a];
		}
		for(int b: gMem[G][1]){
			gCost[0][G][1] += c[0][b];
			gCost[1][G][1] += c[1][b];
		}
		G++;
	}
	if(G > MAX) while(1);

	long long result = 0;
	for(int i=0; i<G; i++)
		result += min(gCost[0][i][0]+gCost[1][i][1], gCost[0][i][1]+gCost[1][i][0]);
	printf("%lld\n", result);

	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		int q, x, y;
		scanf("%d %d %d", &q, &x, &y);
		if(q < 2){
			x--; y--;
			int g1 = gn[x], g2 = gn[y];
			bool s1 = gSide[x], s2 = gSide[y];
			if(g1 < 0 || g2 < 0 || g1 >= G || g2 >= G) while(1);
			if(g1 != g2){

				if(gMem[g1][0].size()+gMem[g1][1].size() < gMem[g2][0].size()+gMem[g2][1].size()){
					swap(g1, g2);
					swap(s1, s2);
				}
				if(q == 0){
					for(int a: gMem[g2][s2]){
						if(gn[a] >= N) while(1);
						gn[a] = g1;
						gSide[a] = s1;
						gMem[g1][s1].push_back(a);
					}
					for(int b: gMem[g2][!s2]){
						if(gn[b] >= N) while(1);
						gn[b] = g1;
						gSide[b] = !s1;
						gMem[g1][!s1].push_back(b);
					}

					long long prevVal = min(gCost[0][g1][0]+gCost[1][g1][1], gCost[0][g1][1]+gCost[1][g1][0])
						+ min(gCost[0][g2][0]+gCost[1][g2][1], gCost[0][g2][1]+gCost[1][g2][0]);

					gCost[0][g1][s1] += gCost[0][g2][s2];
					gCost[0][g1][!s1] += gCost[0][g2][!s2];
					gCost[1][g1][s1] += gCost[1][g2][s2];
					gCost[1][g1][!s1] += gCost[1][g2][!s2];

					long long newVal = min(gCost[0][g1][0]+gCost[1][g1][1], gCost[0][g1][1]+gCost[1][g1][0]);
					result = result - prevVal + newVal;

					gCost[0][g2][0] = gCost[0][g2][1] = gCost[1][g2][0] = gCost[1][g2][1] = 0;
					gMem[g2][s1].clear();
					gMem[g2][s2].clear();
					gMem[g2][s1].resize(0);
					gMem[g2][s2].resize(0);
				}
				else{
					for(int a: gMem[g2][!s2]){
						if(gn[a] >= N) while(1);
						gn[a] = g1;
						gSide[a] = s1;
						gMem[g1][s1].push_back(a);
					}
					for(int b: gMem[g2][s2]){
						if(gn[b] >= N) while(1);
						gn[b] = g1;
						gSide[b] = !s1;
						gMem[g1][!s1].push_back(b);
					}

					long long prevVal = min(gCost[0][g1][0]+gCost[1][g1][1], gCost[0][g1][1]+gCost[1][g1][0])
						+ min(gCost[0][g2][0]+gCost[1][g2][1], gCost[0][g2][1]+gCost[1][g2][0]);

					gCost[0][g1][s1] += gCost[0][g2][!s2];
					gCost[0][g1][!s1] += gCost[0][g2][s2];
					gCost[1][g1][s1] += gCost[1][g2][!s2];
					gCost[1][g1][!s1] += gCost[1][g2][s2];

					long long newVal = min(gCost[0][g1][0]+gCost[1][g1][1], gCost[0][g1][1]+gCost[1][g1][0]);
					result = result - prevVal + newVal;

					gCost[0][g2][0] = gCost[0][g2][1] = gCost[1][g2][0] = gCost[1][g2][1] = 0;
					gMem[g2][s1].clear();
					gMem[g2][s2].clear();
					gMem[g2][s1].resize(0);
					gMem[g2][s2].resize(0);
				}
			}
		}
		else{
			x--;
			int g = gn[x];
			bool s = gSide[x];
			if(g < 0 || g >= G) while(1);

			if(q == 2){
				long long prevVal = min(gCost[0][g][0]+gCost[1][g][1], gCost[0][g][1]+gCost[1][g][0]);

				gCost[0][g][s] = gCost[0][g][s] - c[0][x] + y;
				c[0][x] = y;

				long long newVal = min(gCost[0][g][0]+gCost[1][g][1], gCost[0][g][1]+gCost[1][g][0]);
				result = result - prevVal + newVal;
			}
			else{
				long long prevVal = min(gCost[0][g][0]+gCost[1][g][1], gCost[0][g][1]+gCost[1][g][0]);

				gCost[1][g][s] = gCost[1][g][s] - c[1][x] + y;
				c[1][x] = y;

				long long newVal = min(gCost[0][g][0]+gCost[1][g][1], gCost[0][g][1]+gCost[1][g][0]);
				result = result - prevVal + newVal;
			}
		}
		printf("%lld\n", result);
	}
}