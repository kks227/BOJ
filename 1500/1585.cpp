#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX_V = 2*(MAX_N+1);
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int N, c[MAX_V][MAX_V], d[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int MCMF(){
	int result = 0, f[MAX_V][MAX_V] = {0};
	for(int k=0; k<N; k++){
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = {0};
		queue<int> Q;
		fill(prev, prev+MAX_V, -1);
		fill(dist, dist+MAX_V, INF);
		dist[S] = 0;
		inQ[S] = true;
		Q.push(S);

		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for(int next: adj[curr]){
				if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]){
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if(!inQ[next]){
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if(prev[E] == -1) break;

		for(int i=E; i!=S; i=prev[i]){
			result += d[prev[i]][i];
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
	}
	return result;
}



int main(){
	int t[2][MAX_N], T, F;
	scanf("%d", &N);
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++)
			scanf("%d", &t[i][j]);
		sort(t[i], t[i]+N);
	}
	scanf("%d %d", &T, &F);
	// 절대 만들 수 없는 경우
	for(int i=0; i<N; i++){
		if(t[1][i] <= t[0][i]){
			puts("-1");
			return 0;
		}
	}

	for(int i=0; i<N; i++){
		c[S][i] = c[MAX_N+i][E] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
		adj[MAX_N+i].push_back(E);
		adj[E].push_back(MAX_N+i);

		for(int j=0; j<N; j++){
			if(t[1][j] <= t[0][i]) continue; // 시간차가 최소 1이어야 함
			int temp = max(T-t[1][j]+t[0][i], 0);
			int fine = min(temp*temp, F);
			c[i][MAX_N+j] = 1;
			d[i][MAX_N+j] = fine;
			d[MAX_N+j][i] = -fine;
			adj[i].push_back(MAX_N+j);
			adj[MAX_N+j].push_back(i);
		}
	}

	printf("%d ", MCMF());
	for(int i=0; i<MAX_V; i++)
		for(int j=0; j<MAX_V; j++)
			d[i][j] = -d[i][j];
	printf("%d\n", -MCMF());
}