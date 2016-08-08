#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_V = 300;
const int MAX_E = 5000;

struct Edge{
	int u, v, c, f;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int c1): u(u1), v(v1), c(c1), f(0){}
	int oppo(int s){
		return (s == u ? v : u);
	}
	int spare(int s){
		if(s == u) return c-f;
		return f;
	}
	void addFlow(int s, int nf){
		if(s == u) f += nf;
		else f -= nf;
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		Edge edge[MAX_E];
		vector<Edge*> adj[MAX_V];
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			edge[i] = Edge(a, b, c);
			adj[a].push_back(edge+i);
			adj[b].push_back(edge+i);
		}

		// 최대 유량 total 계산
		int total = 0, S = 0, E = N-1;
		while(1){
			int prev[MAX_V];
			Edge *path[MAX_V] = {0};
			fill(prev, prev+N, -1);
			queue<int> Q;
			Q.push(S);
			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				for(auto *e: adj[curr]){
					int next = e->oppo(curr);
					if(e->spare(curr) > 0 && prev[next] == -1){
						Q.push(next);
						prev[next] = curr;
						path[next] = e;
						if(next == E) break;
					}
				}
			}
			if(prev[E] == -1) break;

			int flow = 1000000000;
			for(int i=E; i!=S; i=prev[i])
				flow = min(flow, path[i]->spare(prev[i]));
			for(int i=E; i!=S; i=prev[i])
				path[i]->addFlow(prev[i], flow);
			total += flow;
		}

		// 포화 상태인 간선 하나하나마다 용량이 줄면 총 유량이 감소하는지 확인
		// 간선이 u->v로 갈 때, 용량이 1 증가했는데도 u에서 v로 유량 1을 흘릴 다른 경로가 있나면 not crucial
		Edge original[MAX_E];
		copy(edge, edge+M, original);
		int result = 0;
		for(int i=0; i<M; i++){
			if(edge[i].c > edge[i].f) continue;

			S = edge[i].u;
			E = edge[i].v;
			edge[i].c--;
			edge[i].f--;
			bool visited[MAX_V] = {0};
			queue<int> Q;
			Q.push(S);
			visited[S] = true;
			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				for(auto *e: adj[curr]){
					int next = e->oppo(curr);
					if(e->spare(curr) > 0 && !visited[next]){
						Q.push(next);
						visited[next] = true;
						if(next == E) break;
					}
				}
			}
			if(!visited[E]) result++;

			copy(original, original+M, edge);
		}
		printf("%d\n", result);
	}
}