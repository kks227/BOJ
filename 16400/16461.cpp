#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int LO = 4000;
const int HI = 6000;
const int I = 20;
const int MOD = 10000;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int S, E, pos[2], dist[MOD*2], a, b;
		fill(dist, dist + MOD*2, INF);
		for(int i = 0; i < 2; ++i){
			scanf("%d.%03d", &a, &b);
			pos[i] = a*1000%MOD + b;
		}
		char c;
		scanf(" %c %d.%03d", &c, &a, &b);
		S = pos[(c == 'B')];
		E = a*1000%MOD + b;
		dist[S] = dist[MOD + S] = 0;

		queue<int> Q;
		Q.push(S);
		Q.push(MOD + S);
		for(int i = 1; i <= 6; ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int curr = Q.front()%MOD, next;
				bool dir = Q.front()/MOD;
				Q.pop();
				for(int j = 0; j < 2; ++j){
					if(curr != pos[j]) continue;
					next = pos[!j] % MOD + dir * MOD;
					if(dist[next] == INF){
						dist[next] = i;
						Q.push(next);
					}
				}
				next = curr + I*(dir ? 1 : -1);
				if(next < LO) next = HI;
				if(next > HI) next = LO;
				next += dir*MOD;
				if(dist[next] == INF){
					dist[next] = i;
					Q.push(next);
				}
			}
		}
		printf("%d\n", min(min(dist[E], dist[MOD + E]), 6));
	}
}