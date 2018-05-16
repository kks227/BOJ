#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int S = MAX_N*2;
const int E = S+1;
const int MAX = E+1;

int main(){
	int N, M, sum[2] = {0}, c[MAX][MAX] = {0}, f[MAX][MAX] = {0};
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &c[S][i]);
		sum[0] += c[S][i];

		adj[S].push_back(i);
		adj[i].push_back(S);
		for(int j=MAX_N; j<MAX_N+M; j++){
			c[i][j] = 1;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	for(int i=MAX_N; i<MAX_N+M; i++){
		scanf("%d", &c[i][E]);
		sum[1] += c[i][E];

		adj[i].push_back(E);
		adj[E].push_back(i);
	}
	if(sum[0] != sum[1]){
		puts("-1");
		return 0;
	}

	int total = 0;
	while(1){
		int prev[MAX];
		fill(prev, prev+MAX, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty() && prev[E] == -1){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(prev[next] == -1 && c[curr][next] > f[curr][next]){
					prev[next] = curr;
					Q.push(next);
				}
			}
		}
		if(prev[E] == -1) break;

		for(int i=E; i!=S; i=prev[i]){
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
		total++;
	}
	if(total < sum[0]){
		puts("-1");
		return 0;
	}

	for(int i=0; i<N; i++){
		for(int j=MAX_N; j<MAX_N+M; j++){
			if(f[i][j] == 0) continue;

			int prev[MAX];
			fill(prev, prev+MAX, -1);
			queue<int> Q;
			Q.push(i);
			while(!Q.empty() && prev[j] == -1){
				int curr = Q.front(); Q.pop();
				for(int next: adj[curr]){
					if(curr < i || curr == i && next < j) continue;
					if(prev[next] == -1 && c[curr][next] > f[curr][next]){
						prev[next] = curr;
						Q.push(next);
					}
				}
			}
			if(prev[j] == -1) continue;

			f[i][j] = f[j][i] = 0;
			for(int k=j; k!=i; k=prev[k]){
				f[prev[k]][k]++;
				f[k][prev[k]]--;
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=MAX_N; j<MAX_N+M; j++)
			printf("%1d", f[i][j]);
		puts("");
	}
}