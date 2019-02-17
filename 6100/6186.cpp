#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX = MAX_N*MAX_N;
const int roff[2] = {-1, 0};
const int coff[2] = {0, -1};

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
	int size(int a){ return -p[f(a)]; }
};

int main(){
	int R, C;
	char map[MAX_N][MAX_N];
	UnionFind UF;
	scanf("%d %d\n", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == '.') continue;
			for(int d = 0; d < 2; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nc < 0) continue;
				if(map[nr][nc] == '#') UF.u(i*MAX_N+j, nr*MAX_N+nc);
			}
		}
		getchar();
	}

	int result = 0;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			if(map[i][j] == '#' && UF.p[i*MAX_N+j] < 0) ++result;
	printf("%d\n", result);
}