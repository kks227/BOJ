#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, K, H[100000] = {0};
	scanf("%d %d", &N, &K);
	unordered_map<int, int> H2N;
	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++){
			int b;
			scanf("%1d", &b);
			H[i] = H[i]*2 + b;
		}
		H2N[H[i]] = i;
	}
	vector<int> adj[100000];
	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++){
			int b = 1<<j;
			if(H[i] & b) continue;

			int o = (H[i] & ((1<<K)-1-b)) + b;
			auto iter = H2N.find(o);
			if(iter != H2N.end()){
				adj[i].push_back(iter->second);
				adj[iter->second].push_back(i);
			}
		}
	}

	int dist[100000], prev[100000];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	for(int i=1; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(dist[next] == INF){
					dist[next] = i;
					prev[next] = curr;
					Q.push(next);
				}
			}
		}
	}

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int E;
		scanf("%d", &E);
		if(dist[--E] == INF) puts("-1");
		else{
			stack<int> S;
			S.push(E);
			for(int i=E; i!=0; i=prev[i]) S.push(prev[i]);
			while(!S.empty()){
				printf("%d ", S.top()+1);
				S.pop();
			}
			puts("");
		}
	}
}