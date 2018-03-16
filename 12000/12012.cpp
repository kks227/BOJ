#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200000;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a); b = f(b);
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
	int N, M, edge[MAX][3] = {0}, closed[MAX];
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[i][0] = --u; edge[i][1] = --v;
		adj[u].push_back(i); adj[v].push_back(i);
	}
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		closed[N-i-1] = --val;
	}

	UnionFind UF;
	bool result[MAX];
	int R = 0;
	for(int i=0; i<N; i++){
		int v = closed[i];
		for(int e: adj[v])
			if(++edge[e][2] == 2) UF.u(edge[e][0], edge[e][1]);
		result[R++] = (-UF.p[UF.f(v)] == i+1);
	}
	while(R > 0) puts(result[--R] ? "YES" : "NO");
}