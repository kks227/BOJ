#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX_M = 3000;
const int MAX = MAX_N*MAX_N;
const int MAX_Q = MAX_N*(MAX_N-1)/2;
const int MAX_C = 40000;
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
	int N, M, C[MAX_N], Q, q[MAX][2];
	vector<int> adj[MAX_N];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", C+i);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		scanf("%d %d", &q[i][0], &q[i][1]);
		--q[i][0]; --q[i][1];
	}

	int need[MAX_N][MAX_N], H2N[MAX], H = 0;
	set<int> S;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			need[i][j] = C[i]*C[j];
			S.insert(need[i][j]);
		}
	}
	unordered_map<int, int> N2H;
	for(int i: S){
		H2N[H] = i;
		N2H[i] = H++;
	}
	vector<P> V;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			V.push_back(P(N2H[need[i][j]], i*MAX_N + j));
	sort(V.begin(), V.end());

	int lo[MAX_Q] = {0}, hi[MAX_Q];
	fill(hi, hi+Q, H+1);
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
		bool opened[MAX] = {false,};
		for(int i = 0, j = 0; i < H; ++i){
			while(j < V.size() && V[j].first == i){
				int curr = V[j++].second;
				int u = curr/MAX_N, v = curr%MAX_N;
				opened[curr] = true;
				for(int w: adj[u])
					if(opened[w*MAX_N + v]) UF.u(w*MAX_N + v, curr);
				for(int w: adj[v])
					if(opened[u*MAX_N + w]) UF.u(u*MAX_N + w, curr);
			}

			for(int k: G[i+1]){
				int u = q[k][0], v = q[k][1];
				int a = u*MAX_N + v, b = v*MAX_N + u;
				if(opened[a] && opened[b] && UF.f(a) == UF.f(b)) hi[k] = i+1;
				else lo[k] = i+1;
			}
		}
	}

	for(int i = 0; i < Q; ++i)
		printf("%d\n", H2N[hi[i]-1]);
}