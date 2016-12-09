#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const function<int(int)> f[3] = {
	[](int n){ return n-1; },
	[](int n){ return n+1; },
	[](int n){ return n*2; }
};

int N, K, dp[100001];
vector<int> adj[100001];

int HS(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;
	if(curr == N) return ret = 1;

	ret = 0;
	for(int next: adj[curr])
		ret += HS(next);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	int dist[100001];
	fill(dist, dist+100001, INF);
	dist[N] = 0;

	queue<int> Q;
	Q.push(N);
	for(int i=1; dist[K]==INF; i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int curr = Q.front();
			Q.pop();
			for(int k=0; k<3; k++){
				int next = f[k](curr);
				if(next < 0 || next > 100000) continue;

				if(dist[next] == INF){
					dist[next] = i;
					adj[next].push_back(curr);
					Q.push(next);
				}
				else if(dist[next] == i) adj[next].push_back(curr);
			}
		}
	}

	fill(dp, dp+100001, -1);
	printf("%d\n%d\n", dist[K], HS(K));
}