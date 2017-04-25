#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;
char map[10000][500];

bool dfs(int r, int c){
	map[r][c] = 'x';
	if(c == C-1) return true;

	for(int k=-1; k<=1; k++){
		int nr = r + k;
		if(nr < 0 || nr >= R || map[nr][c+1] == 'x') continue;
		if(dfs(nr, c+1)) return true;
	}
	return false;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}

	int result = 0;
	for(int i=0; i<R; i++)
		if(dfs(i, 0)) result++;
	printf("%d\n", result);
}