#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000001;

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
	int N, M;
	scanf("%d %d", &N, &M);
	UnionFind UF;
	for(int i=0; i<M; i++){
		int o, p, q;
		scanf("%d %d %d", &o, &p, &q);
		if(o == 0) UF.u(p, q);
		else puts(UF.f(p) == UF.f(q) ? "YES" : "NO");
	}
}