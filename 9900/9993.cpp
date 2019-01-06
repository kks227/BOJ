#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1001;
const int MAX = MAX_N*MAX_N*2;

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
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == '/'){
				UF.u(i*MAX_N+j, i*MAX_N+j + MAX_N*MAX_N);
				UF.u((i+1)*MAX_N+j, i*MAX_N+j+1 + MAX_N*MAX_N);
			}
			else{
				UF.u(i*MAX_N+j, i*MAX_N+j+1 + MAX_N*MAX_N);
				UF.u((i+1)*MAX_N+j, i*MAX_N+j + MAX_N*MAX_N);
			}
		}
	}
	int result = 0;
	for(int i = 0; i < R; ++i){
		result = max(UF.size(i*MAX_N + MAX_N*MAX_N), result);
		result = max(UF.size(i*MAX_N+C + MAX_N*MAX_N), result);
	}
	for(int j = 0; j < C; ++j){
		result = max(UF.size(j), result);
		result = max(UF.size(R*MAX_N+j), result);
	}
	printf("%d\n", result-1);
}