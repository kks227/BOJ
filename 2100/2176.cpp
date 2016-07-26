#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int S = 0, T = 1;

int N, M, dp[1000], dist[1000];
vector<P> adj[1000];

int cntReasonalPaths(int curr){
	if(curr == T) return 1;
	int &ret = dp[curr];
	if(ret != -1) return ret;

	ret = 0;
	for(auto &p: adj[curr])
		if(dist[p.first] < dist[curr])
			ret += cntReasonalPaths(p.first);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		A--; B--;
		adj[A].push_back(P(B, C));
		adj[B].push_back(P(A, C));
	}
	
	bool visited[1000] = {0};
	fill(dist, dist+N, 0x7fffffff);
	dist[T] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, T));
	for(int i=0; i<N-1; i++){
		int curr = -1;
		while(!PQ.empty()){
			int temp = PQ.top().second;
			PQ.pop();
			if(!visited[temp]){
				curr = temp;
				break;
			}
		}
		if(curr == -1) break;

		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first;
			int d = p.second;
			if(!visited[next] && dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", cntReasonalPaths(S));
}