#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_D = 17; // ceil of log(2, MAX);

int main(){
	int N, parent[MAX][MAX_D], depth[MAX];
	vector<int> child[MAX];
	scanf("%d", &N);
	memset(parent, -1, sizeof(parent));
	depth[0] = 0;
	for(int i = 1; i < N; ++i){
		int p;
		scanf("%d", &p);
		child[--p].push_back(i);
		parent[i][0] = p;
		depth[i] = depth[p] + 1;
	}
	for(int i = 0; i < N; ++i)
		sort(child[i].begin(), child[i].end());
	for(int j = 0; j < MAX_D-1; ++j)
		for(int i = 1; i < N; ++i)
			if(parent[i][j] != -1) parent[i][j+1] = parent[ parent[i][j] ][j];

	queue<int> Q;
	Q.push(0);
	int prev = -1;
	long long result = 0;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		if(prev != -1){
			int u = curr, v = prev;
			if(depth[u] < depth[v]) swap(u, v);
			int diff = depth[u] - depth[v];
			for(int j = 0; diff > 0; ++j){
				if(diff % 2) u = parent[u][j];
				diff /= 2;
			}
			if(u != v){
				for(int j = MAX_D-1; j >= 0; --j){
					if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
						u = parent[u][j];
						v = parent[v][j];
					}
				}
				u = parent[u][0];
			}
			result += depth[curr] + depth[prev] - 2*depth[u];
		}
		prev = curr;

		for(int next: child[curr]) Q.push(next);
	}
	printf("%lld\n", result);
}