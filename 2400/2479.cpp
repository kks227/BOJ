#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int N, K, S, E;
	char W[1000][31];
	vector<int> adj[1000];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%s", W[i]);
		for(int j=0; j<i; j++){
			int cnt = 0;
			for(int k=0; k<K; k++)
				if(W[i][k] != W[j][k] && ++cnt == 2) break;
			if(cnt == 1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	scanf("%d %d", &S, &E);
	S--; E--;

	int prev[1000];
	bool visited[1000] = {0};
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(!visited[next]){
				visited[next] = true;
				prev[next] = curr;
				Q.push(next);
			}
		}
	}

	if(!visited[E]) puts("-1");
	else{
		vector<int> path;
		for(int i=E; i!=S; i=prev[i])
			path.push_back(i);
		path.push_back(S);
		for(int i=path.size()-1; i>=0; i--)
			printf("%d ", path[i]+1);
	}
}