#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 300000;

int main(){
	int N, M, K, S;
	vector<int> adj[MAX];
	scanf("%d %d %d %d", &N, &M, &K, &S);
	--S;
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
	}
	queue<int> Q;
	Q.push(S);
	int dist[MAX];
	fill(dist, dist + N, -1);
	dist[S] = 0;
	vector<int> result;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		if(dist[curr] == K) result.push_back(curr);
		for(int next: adj[curr]){
			if(dist[next] == -1){
				dist[next] = dist[curr] + 1;
				Q.push(next);
			}
		}
	}
	if(result.empty()) puts("-1");
	else{
		sort(result.begin(), result.end());
		for(int u: result)
			printf("%d\n", u+1);
	}
}