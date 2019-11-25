#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	int getSize(int a){ return -p[f(a)]; }
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
	int Q;
	UnionFind UF;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		char op;
		int a, b;
		scanf(" %c %d", &op, &a);
		--a;
		if(op == 'I'){
			scanf("%d", &b);
			UF.u(a, b-1);
		}
		else printf("%d\n", UF.getSize(a));
	}
}