#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100000;
const int MAX_E = 200000;
const int INF = 1e9;
typedef pair<int, int> P;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		if(p[a] < p[b]){
			p[a] += p[b];
			p[b] = a;
		}
		else{
			p[b] += p[a];
			p[a] = b;
		}
		return true;
	}
};

int main(){
	int N, E, K, Q, q[MAX][2];
	vector<P> adj[MAX];
	scanf("%d %d %d %d", &N, &E, &K, &Q);
	for(int i = 0; i < E; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	int dist[MAX];
	fill(dist, dist+N, INF);
	bool visited[MAX] = {false,};
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i = 0; i < K; ++i){
		int u;
		scanf("%d", &u);
		--u;
		dist[u] = 0;
		PQ.push(P(0, u));
	}
	for(int i = 0; i < Q; ++i){
		scanf("%d %d", &q[i][0], &q[i][1]);
		--q[i][0]; --q[i][1];
	}

	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr]+d){
				dist[next] = dist[curr]+d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	set<int> S;
	int H2I[MAX], M = 0;
	unordered_map<int, int> I2H;
	P open[MAX];
	for(int i = 0; i < N; ++i)
		S.insert(dist[i]);
	for(int i: S){
		H2I[M] = i;
		I2H[i] = M++;
	}
	for(int i = 0; i < N; ++i)
		open[i] = P(M-1-I2H[dist[i]], i);
	sort(open, open+N);

	int lo[MAX] = {0}, hi[MAX];
	fill(hi, hi+Q, M+1);
	while(1){
		bool flag = false;
		vector<int> G[MAX+1];
		for(int i = 0; i < Q; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		UnionFind UF;
		for(int i = 0, j = 0; i < M; ++i){
			do{
				int u = open[j].second, w = open[j].first;
				if(w > i) break;
				for(auto &p: adj[u]){
					int v = p.first;
					if(dist[u] <= dist[v]) UF.u(u, v);
				}
			}while(++j < N);
			for(int k: G[i+1]){
				int a = UF.f(q[k][0]), b = UF.f(q[k][1]);
				(a == b ? hi : lo)[k] = i+1;
			}
		}
	}

	for(int i = 0; i < Q; ++i)
		printf("%d\n", H2I[M-hi[i]]);
}