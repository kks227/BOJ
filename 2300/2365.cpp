#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX_V = 2*MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;

int main(){
	int N, c[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
	vector<int> adj[MAX_V];
	scanf("%d", &N);

	int dest = 0;
	for(int i=0; i<N; i++){
		adj[S].push_back(i);
		adj[i].push_back(S);
		scanf("%d", &c[S][i]);
		dest += c[S][i];
		for(int j=0; j<N; j++){
			adj[i].push_back(MAX_N+j);
			adj[MAX_N+j].push_back(i);
		}
	}
	for(int i=0; i<N; i++){
		adj[MAX_N+i].push_back(E);
		adj[E].push_back(MAX_N+i);
		scanf("%d", &c[MAX_N+i][E]);
	}

	// 행에서 열로 보내는 간선 대역폭을 1씩 늘려가며 최초로 가능할 때까지 시도
	int total = 0;
	while(total < dest){
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				c[i][MAX_N+j]++;

		while(1){
			int prev[MAX_V];
			fill(prev, prev+MAX_V, -1);
			queue<int> Q;
			Q.push(S);
			while(!Q.empty() && prev[E] == -1){
				int curr = Q.front();
				Q.pop();
				for(int next: adj[curr]){
					if(c[curr][next]-f[curr][next] > 0 && prev[next] == -1){
						prev[next] = curr;
						Q.push(next);
						if(next == E) break;
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
	}
	printf("%d\n", c[0][MAX_N]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ", f[i][MAX_N+j]);
		puts("");
	}
}