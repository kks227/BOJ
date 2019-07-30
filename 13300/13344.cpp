#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50000;
const int MAX_M = 250000;

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
	int N, M, K = 0, e[MAX_M][2], ind[MAX] = {0,};
	UnionFind UF;
	vector<int> adj[MAX_M];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		char op;
		scanf("%d %c %d", &e[K][0], &op, &e[K][1]);
		if(op == '=') UF.u(e[K][0], e[K][1]);
		else ++K;
	}
	for(int i = 0; i < K; ++i){
		int u = UF.f(e[i][0]), v = UF.f(e[i][1]);
		adj[u].push_back(v);
		++ind[v];
	}

	queue<int> Q;
	for(int i = 0; i < N; ++i)
		if(ind[i] == 0) Q.push(i);
	for(int i = 0; i < N; ++i){
		if(Q.empty()){
			puts("inconsistent");
			return 0;
		}
		int curr = Q.front();
		Q.pop();
		for(int next: adj[curr])
			if(--ind[next] == 0) Q.push(next);
	}
	puts("consistent");
}