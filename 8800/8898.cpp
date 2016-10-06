#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int INF = 1000000000;

int N, A[MAX], B[MAX], dist[MAX];
bool used[MAX], visited[MAX*2];
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

void floodFill(int curr){
	visited[curr] = true;
	if(curr >= MAX && !visited[B[curr-MAX]]) floodFill(B[curr-MAX]);
	else{
		for(int next: adj[curr])
			if(B[next] != curr && !visited[next+MAX]) floodFill(next+MAX);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int k=0; k<T; k++){
		int s[MAX], d[MAX], t[MAX][MAX];
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", s+i);
		for(int i=0; i<N; i++)
			scanf("%d", d+i);
		for(int i=0; i<N; i++){
			for(int j=i; j<N; j++){
				scanf("%d", &t[i][j]);
				t[j][i] = t[i][j];
			}
		}
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(s[i]+d[i]+t[i][j] <= s[j]) adj[i].push_back(j);

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
		printf("%d\n", N-match);

		fill(visited, visited+MAX*2, false);
		for(int i=0; i<N; i++)
			if(!used[i]) floodFill(i);
		for(int i=0; i<N; i++)
			if(visited[i] && !visited[MAX+i]) printf("%d ", i+1);
		puts("");

		fill(used, used+MAX, false);
		for(int i=0; i<N; i++)
			adj[i].clear();
	}
}