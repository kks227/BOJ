#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e18;
typedef pair<int, int> P;

int main(){
	int N, M, C;
	long long dSum = 0;
	vector<P> adj[100000];
	scanf("%d %d %d", &N, &M, &C);
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		adj[a].push_back(P(b, c));
		adj[b].push_back(P(a, c));
		dSum += c;
	}

	long long dist[100000], result = dSum;
	bool visited[100000] = {0};
	fill(dist, dist+N, INF);
	dist[0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = get<1>(PQ.top());
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;

		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(visited[next]) dSum -= d;
		}
		result = min(result, dist[curr]*C + dSum);

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	printf("%lld\n", result);
}