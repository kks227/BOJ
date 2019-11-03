#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50000;

int main(){
	int N, M;
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int dist[MAX], cnt1 = 0, cnt2 = 0;
	fill(dist, dist+MAX, -1);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	for(int i = 0; !Q.empty(); ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int curr = Q.front(); Q.pop();
			++(i%2 ? cnt2 : cnt1);
			for(int next: adj[curr]){
				if(dist[next] == -1){
					dist[next] = i+1;
					Q.push(next);
				}
				else if(dist[next] == i){
					puts("0");
					return 0;
				}
			}
		}
	}
	printf("%lld\n", 2LL*cnt1*cnt2);
}