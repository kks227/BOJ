#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 300001;

struct UnionFind{
	int p[MAX];
	UnionFind(){ for(int i=0; i<MAX; i++) p[i] = -i; }
	int f(int a){
		if(p[a] <= 0) return a;
		return p[a] = f(p[a]);
	}
	void u(int a, int b){
		a = f(a); b = f(b);
		if(a == b) p[a] = 0;
		else p[b] = a;
	}
};

int main(){
	int N, Q, adj[MAX] = {0}, query[MAX][2];
	bool erased[MAX] = {false};
	scanf("%d ", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", adj+i);
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		scanf("%d %d", &query[i][0], &query[i][1]);
		if(query[i][0] == 2) erased[query[i][1]] = true;
	}

	UnionFind UF;
	int R = 0, result[MAX];
	for(int i=1; i<=N; i++)
		if(adj[i] > 0 && !erased[i]) UF.u(adj[i], i);
	for(int i=Q-1; i>=0; i--){
		int v = query[i][1];
		if(query[i][0] == 1) result[R++] = -UF.p[UF.f(v)];
		else UF.u(adj[v], v);
	}
	while(R-- > 0){
		if(result[R]) printf("%d\n", result[R]);
		else puts("CIKLUS");
	}
}