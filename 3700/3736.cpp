#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int INF = 1000000000;

int N, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

void bfs(){
	queue<int> Q;
	for(int i=0; i<N; i++){
		if(!used[i]){
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = INF;
	}

	while(!Q.empty()){
		int a = Q.front();
		Q.pop();
		for(int b: adj[a]){
			if(B[b] != -1 && dist[B[b]] == INF){
				dist[B[b]] = dist[a] + 1;
				Q.push(B[b]);
			}
		}
	}
}

bool dfs(int a){
	for(int b: adj[a]){
		if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
			used[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	while(scanf("%d", &N) > 0){
		for(int i=0; i<N; i++){
			int job, J;
			scanf("%d: (%d)", &job, &J);
			for(int j=0; j<J; j++){
				int server;
				scanf("%d", &server);
				adj[job].push_back(server-N);
			}
		}

		int match = 0;
		fill(A, A+MAX, -1);
		fill(B, B+MAX, -1);
		while(1){
			bfs();
			int flow = 0;
			for(int i=0; i<N; i++)
				if(!used[i] && dfs(i)) flow++;
			if(flow == 0) break;
			match += flow;
		}
		printf("%d\n", match);

		fill(used, used+MAX, false);
		for(int i=0; i<N; i++)
			adj[i].clear();
	}
}