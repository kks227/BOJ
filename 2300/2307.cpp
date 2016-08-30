#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

struct Edge{
	int to, d;
	bool locked;
	Edge *dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int d1): to(to1), d(d1), locked(false), dual(nullptr){}
};

int N, M, pre[1000];
vector<Edge*> adj[1000];
Edge *path[1000] = {nullptr};

int Dijkstra(bool flag = false){
	int dist[1000];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	bool visited[1000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));

	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;

		visited[curr] = true;
		for(Edge *e: adj[curr]){
			int next = e->to, d = e->d;
			if(e->locked || visited[next]) continue;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
				if(flag){
					pre[next] = curr;
					path[next] = e;
				}
			}
		}
	}
	return dist[N-1];
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		Edge *e1 = new Edge(b, c), *e2 = new Edge(a, c);
		e1->dual = e2;
		e2->dual = e1;
		adj[a].push_back(e1);
		adj[b].push_back(e2);
	}

	int before = Dijkstra(true), after = before;
	Edge *cp[1000] = {nullptr};
	int len = 0;
	for(int i=0, j=N-1; j!=0; i++, j=pre[j]){
		cp[i] = path[j];
		len++;
	}
	for(int i=0; i<len; i++){
		cp[i]->locked = cp[i]->dual->locked = true;
		after = max(after, Dijkstra());
		cp[i]->locked = cp[i]->dual->locked = false;
	}
	printf("%d\n", (after == INF ? -1 : after-before));
}