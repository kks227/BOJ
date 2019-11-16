#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

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
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return true;
	}
	int getSize(int a){ return -p[f(a)]; }
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, M;
		scanf("%d %d", &N, &M);
		UnionFind UF;
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			UF.u(u-1, v-1);
		}
		puts(M == N-1 && UF.getSize(0) == N ? "tree" : "graph");
	}
}