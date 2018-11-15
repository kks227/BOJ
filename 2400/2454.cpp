#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int N, K;
vector<int> adj[300000];

P dfs(int curr, int prev){
	int sum = 0, a = 0, b = 0;
	for(int next: adj[curr]){
		if(next != prev){
			P p = dfs(next, curr);
			if(a < p.first){
				b = a;
				a = p.first;
			}
			else if(b < p.first) b = p.first;
			sum += p.second;
		}
	}
	if(a + b > K+1) return P(0, sum-1);
	if(a > 0) return P(a-1, sum);
	return P(K, sum+1);
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	printf("%d\n", dfs(0, -1).second);
}