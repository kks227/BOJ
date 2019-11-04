#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 700;
const int MAX_E = 123456;
const int MAX_Q = 50000;
typedef pair<int, int> P;

struct UnionFind{
	short p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	short f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int V, E, Q, e[MAX_E][2], q[MAX_Q][2];
	P p[MAX_Q];
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		e[i][0] = --u;
		e[i][1] = --v;
	}
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		scanf("%d %d", &q[i][0], &q[i][1]);
		p[i] = P(--q[i][0], i);
	}
	sort(p, p+Q);
	UnionFind currUF, UF[MAX_Q];
	for(int i = 0, j = 0; i < Q; ++i){
		int qn = p[i].second;
		for(; j < q[qn][0]; ++j)
			currUF.u(e[j][0], e[j][1]);
		copy(currUF.p, currUF.p+MAX, UF[qn].p);
	}
	for(int i = 0; i < Q; ++i)
		p[i] = P(q[i][1], i);
	sort(p, p+Q);
	currUF = UnionFind();
	for(int i = Q-1, j = E; i >= 0; --i){
		int qn = p[i].second;
		for(; j > q[qn][1]; --j)
			currUF.u(e[j-1][0], e[j-1][1]);
		for(int k = 0; k < V; ++k)
			UF[qn].u(currUF.f(k), k);
	}

	for(int i = 0; i < Q; ++i){
		int result = 0;
		for(int j = 0; j < V; ++j)
			if(UF[i].p[j] < 0) ++result;
		printf("%d\n", result);
	}
}