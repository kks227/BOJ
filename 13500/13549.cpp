#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const bool cost[3] = {1, 1, 0};
const function<int(int)> f[3] = {
	[](int n){ return n-1; },
	[](int n){ return n+1; },
	[](int n){ return n*2; }
};
typedef pair<int, int> P;

int main(){
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	bool visited[100001] = {0};
	int dist[100001];
	fill(dist, dist+100001, INF);
	dist[N] = 0;

	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, N));
	while(1){
		int curr = PQ.top().second;
		PQ.pop();
		if(visited[curr]) continue;
		if(curr == K) break;
		
		visited[curr] = true;
		for(int i=0; i<3; i++){
			int next = f[i](curr);
			if(next < 0 || next > 100000) continue;
			if(dist[next] > dist[curr] + cost[i]){
				dist[next] = dist[curr] + cost[i];
				PQ.push(P(dist[next], next));
			}
		}
	}
	printf("%d\n", dist[K]);
}