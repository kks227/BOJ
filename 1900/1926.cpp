#include <cstdio>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int N, M, C, L, cnt;
bool map[500][500];

void DFS(int r, int c){
	map[r][c] = false;
	cnt++;
	for(int d=0; d<4; d++){
		int nr = r+roff[d];
		int nc = c+coff[d];
		if(nr<0 || nr>=N || nc<0 || nc>=M || !map[nr][nc]) continue;
		DFS(nr, nc);
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &map[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(map[i][j]){
				cnt = 0;
				DFS(i, j);
				C++;
				L = max(L, cnt);
			}
	printf("%d\n%d\n", C, L);
}