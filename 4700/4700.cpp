#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;

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
		for(int i = 0; i < N; ++i)
			if(indegree[i] == 0) Q.push(i);
		int cnt = 0, result = 1;
		while(!Q.empty()){
			if(Q.size() > 1) result = 2;
			int curr = Q.front(); Q.pop();
			++cnt;
			for(int next: adj[curr])
				if(--indegree[next] == 0) Q.push(next);
		}
		if(cnt < N) result = 0;
		printf("%d\n", result);
	}
}