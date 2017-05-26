#include <cstdio>
#include <algorithm>
using namespace std;
const int roff[4] = {0, -1, 0, 1};
const int coff[4] = {-1, 0, 1, 0};

struct UnionFind{
	int p[2500];
	UnionFind(){ fill(p, p+2500, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int R, C;
	UnionFind UF;
	scanf("%d %d", &C, &R);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			int adj;
			scanf("%d", &adj);
			for(int d=0; d<4; d++, adj/=2)
				if(adj%2 == 0) UF.u(i*50 + j, (i+roff[d])*50 + j+coff[d]);
		}
	}
	int r[3] = {0};
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(UF.p[i*50 + j] < 0){
				r[0]++;
				r[1] = max(r[1], -UF.p[i*50 + j]);
			}
			for(int d=0; d<4; d++){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				int a = UF.f(i*50 + j), b = UF.f(nr*50 + nc);
				if(a != b) r[2] = max(r[2], -UF.p[a]-UF.p[b]);
			}
		}
	}
	printf("%d\n%d\n%d\n", r[0], r[1], r[2]);
}