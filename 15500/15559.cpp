#include <cstdio>
#include <unordered_map>
using namespace std;
const int roff[4] = {-1, 0, 0, 1};
const int coff[4] = {0, -1, 1, 0};

int R, C, map[1000][1000], dfsn[1000][1000], dcnt, result = 0;

void dfs(int r, int c, int k){
	dfsn[r][c] = k;
	int nr = r + roff[map[r][c]], nc = c + coff[map[r][c]];
	if(dfsn[nr][nc] == 0) dfs(nr, nc, k);
	else if(dfsn[nr][nc] == k) result++;
}

int main(){
	unordered_map<char, int> C2I;
	C2I['N'] = 0; C2I['W'] = 1; C2I['E'] = 2; C2I['S'] = 3;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = C2I[getchar()];
	}
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(dfsn[i][j] == 0) dfs(i, j, ++dcnt);
	printf("%d\n", result);
}