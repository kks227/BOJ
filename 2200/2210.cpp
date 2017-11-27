#include <cstdio>
#include <set>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int map[5][5];
set<int> S;

void dfs(int r, int c, int k, int val){
	for(int d=0; d<4; d++){
		int nr = r+roff[d], nc = c+coff[d];
		if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
		int nval = val*10 + map[nr][nc];
		if(k == 4) S.insert(nval);
		else dfs(nr, nc, k+1, nval);
	}
}

int main(){
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			scanf("%d", &map[i][j]);
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			dfs(i, j, 0, map[i][j]);
	printf("%d\n", S.size());
}