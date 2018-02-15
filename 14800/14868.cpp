#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct UnionFind{
	int p[100000];
	UnionFind(){ fill(p, p+100000, -1); }
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
	int N, K, map[2000][2000];
	scanf("%d %d", &N, &K);
	memset(map, -1, sizeof(map));
	queue<int> Q;
	UnionFind UF;
	for(int i=0; i<K; i++){
		int r, c;
		scanf("%d %d", &c, &r);
		r--; c--;
		map[r][c] = i;
		Q.push(r*2000 + c);
		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] < 0) continue;
			UF.u(map[r][c], map[nr][nc]);
		}
	}

	int result = 0;
	for(; UF.p[UF.f(0)] > -K; result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/2000, c = Q.front()%2000; Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] >= 0) continue;
				map[nr][nc] = map[r][c];
				Q.push(nr*2000 + nc);
				for(int dd=0; dd<4; dd++){
					int nnr = nr+roff[dd], nnc = nc+coff[dd];
					if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= N || map[nnr][nnc] < 0) continue;
					UF.u(map[nnr][nnc], map[r][c]);
				}
			}
		}
	}
	printf("%d\n", result);
}