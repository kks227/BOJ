#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

struct Edge{
	int u, v, c, f;
	Edge *dual;
	Edge(): Edge(0, 0, 0){}
	Edge(int u1, int v1, int c1): u(u1), v(v1), c(c1), f(0), dual(nullptr){}
	int residual(){ return c - f; }
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

int main(){
	int N, M, C;
	vector<P> adj1[25000];
	scanf("%d %d %d", &N, &M, &C);
	for(int i=0; i<M; i++){
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		x--; y--;
		adj1[x].push_back(P(y, t));
		adj1[y].push_back(P(x, t));
	}

	priority_queue<P, vector<P>, greater<P>> PQ;
	int dist[25000];
	fill(dist, dist+N, INF);
	bool visited[25000] = {false};
	dist[0] = 0;
	PQ.push(P(0, 0));
	for(int i=0; i<N-1; i++){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr]);
		visited[curr] = true;

		for(auto &p: adj1[curr]){
			int &next = p.first, &d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	P div[25000];
	for(int i=0; i<C; i++){
		int s;
		scanf("%d", &s);
		div[i] = P(dist[s-1], s-1);
	}
	sort(div, div+C);

	vector<Edge*> edge;
	vector<Edge*> adj2[25000];
	for(int i=0; i<N; i++){
		for(auto &p: adj1[i]){
			int j = p.first, d = p.second;
			if(dist[i]+d == dist[j]){
				Edge *e1 = new Edge(i, j, 0), *e2 = new Edge(j, i, 1);
				e1->dual = e2;
				e2->dual = e1;
				edge.push_back(e1);
				edge.push_back(e2);
				adj2[i].push_back(e1);
				adj2[j].push_back(e2);
			}
		}
	}

	int result = 0;
	for(int i=1, j=0; i<=C; i++){
		if(i == C || div[i].first != div[i-1].first){
			for(int k=j; k<i; k++){
				int S = div[k].second;
				bool visited[25000] = {false};
				Edge* path[25000] = {nullptr};
				queue<int> Q;
				Q.push(S);
				visited[S] = true;
				while(!visited[0] && !Q.empty()){
					int curr = Q.front();
					Q.pop();
					for(Edge* e: adj2[curr]){
						int next = e->v;
						if(e->residual() > 0 && !visited[next]){
							visited[next] = true;
							path[next] = e;
							Q.push(next);
						}
					}
				}
				if(visited[0]){
					result++;
					for(int curr=0; curr!=S; curr=path[curr]->u)
						path[curr]->addFlow(1);
				}
			}

			if(i == C){
				for(Edge* e: edge)
					delete e;
			}
			else{
				for(Edge *e: edge)
					e->f = 0;
			}
			j = i;
		}
	}
	printf("%d\n", result);
}