#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		vector<int> adj[MAX];
		int indegree[MAX] = {0,};
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			++indegree[v];
		}

		queue<int> Q;
		vector<int> result;
		for(int i = 0; i < N; ++i)
			if(indegree[i] == 0) Q.push(i);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			result.push_back(curr);
			for(int next: adj[curr])
				if(--indegree[next] == 0) Q.push(next);
		}
		if(result.size() < N) puts("IMPOSSIBLE");
		else{
			for(int i: result)
				printf("%d\n", i+1);
		}
	}
}