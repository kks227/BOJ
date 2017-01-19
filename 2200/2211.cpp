#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int main(){
	int N, M;
	vector<P> adj[1000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		A--; B--;
		adj[A].push_back(P(B, C));
		adj[B].push_back(P(A, C));
	}

	int dist[1000], prev[1000];
	bool visited[1000] = {false};
	fill(dist, dist+N, INF);
	fill(prev, prev+N, -1);
	dist[0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	for(int i=0; i<N; i++){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				prev[next] = curr;
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	printf("%d\n", N-1);
	for(int i=1; i<N; i++)
		printf("%d %d\n", i+1, prev[i]+1);
}