#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M;
	vector<int> adj[20000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	priority_queue<P, vector<P>, greater<P>> PQ;
	int dist[20000];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	bool visited[20000] = {false};
	PQ.push(P(0, 0));
	for(int i=0; i<N-1; i++){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr]);
		visited[curr] = true;

		for(int next: adj[curr]){
			if(dist[next] > dist[curr]+1){
				dist[next] = dist[curr]+1;
				PQ.push(P(dist[next], next));
			}
		}
	}
	
	int d = -1, result = -1, cnt = 0;
	for(int i=0; i<N; i++){
		if(d < dist[i]){
			d = dist[i];
			result = i;
			cnt = 1;
		}
		else if(d == dist[i]) cnt++;
	}
	printf("%d %d %d\n", result+1, d, cnt);
}