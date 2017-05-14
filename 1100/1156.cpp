#include <cstdio>
#include <cstring>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};

int uf[10000];

int uf_find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = uf_find(uf[a]);
}

bool uf_union(int a, int b){
	a = uf_find(a);
	b = uf_find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}

int main(){
	int N, K, R, r[100], c[100];
	bool adj[100][100][4] = {0};
	scanf("%d %d %d", &N, &K, &R);
	for(int i=0; i<R; i++){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--; c1--; r2--; c2--;
		for(int d=0; d<4; d++){
			if(r1+roff[d] == r2 && c1+coff[d] == c2){
				adj[r1][c1][d] = adj[r2][c2][(d+2)%4] = true;
				break;
			}
		}
	}
	for(int i=0; i<K; i++){
		scanf("%d %d", r+i, c+i);
		r[i]--; c[i]--;
	}

	memset(uf, -1, sizeof(uf));
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int d=0; d<4; d++){
				int ni = i+roff[d], nj = j+coff[d];
				if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
				if(!adj[i][j][d]) uf_union(i*100+j, ni*100+nj);
			}
		}
	}
	int result = 0;
	for(int i=0; i<K; i++)
		for(int j=i+1; j<K; j++)
			if(uf_find(r[i]*100+c[i]) != uf_find(r[j]*100+c[j])) result++;
	printf("%d\n", result);
}