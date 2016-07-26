#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> TS;
vector<vector<int>> adj;
vector<bool> visited;

void DFS(int current){
	if(visited[current]) return;
	visited[current] = true;
	for(int next: adj[current])
		DFS(next);
	TS.push_back(current);
}

int main(){
	int M;
	scanf("%d %d", &N, &M);
	adj.resize(N);
	visited.resize(N);
	for(int i=0; i<M; i++){
		int K, prev, curr;
		scanf("%d %d", &K, &prev);
		for(int i=1; i<K; i++){
			scanf("%d", &curr);
			adj[prev-1].push_back(curr-1);
			prev = curr;
		}
	}
	for(int i=0; i<N; i++)
		DFS(i);
	reverse(TS.begin(), TS.end());
	vector<int> pos(N);
	for(int i=0; i<N; i++)
		pos[TS[i]] = i;
	for(int i=0; i<N; i++){
		for(int next: adj[i]){
			if(pos[i] > pos[next]){
				puts("0");
				return 0;
			}
		}
	}
	for(int current: TS)
		printf("%d\n", current+1);
}