#include <cstdio>
#include <cstring>
using namespace std;
const int roff[6] = {-1, -1, 0, 1, 1, 0};
const int coff[6] = {0, 1, 1, 0, -1, -1};

int uf[10000], N;

inline int cnum(int r, int c){ return r*N + c; }

int find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = find(uf[n]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b) uf[b] = a;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		memset(uf, -1, sizeof(uf));
		char map[100][100];
		for(int i=0; i<N; i++){
			getchar();
			for(int j=0; j<N; j++)
				map[i][j] = getchar();
		}
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++){
				if(map[i][j] == '.') continue;
				for(int d=0; d<6; d++){
					int ni = i+roff[d];
					int nj = j+coff[d];
					if(ni<0 || ni>=N || nj<0 || nj>=N) continue;
					if(map[ni][nj] == map[i][j])
						merge(cnum(i, j), cnum(ni, nj));
				}
			}
		bool tie = true;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(find(cnum(0, i))==find(cnum(N-1, j)) && map[0][i]=='B'){
					puts("Black wins");
					tie = false;
					break;
				}
				if(find(cnum(i, 0))==find(cnum(j, N-1)) && map[i][0]=='W'){
					puts("White wins");
					tie = false;
					break;
				}
			}
			if(!tie) break;
		}
		if(tie) puts("Not finished");
	}
}