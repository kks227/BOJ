#include <cstdio>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int N, M;
char map[100][100];
bool visited[100][100];

int dfs(int r, int c){
	int result = 1;
	visited[r][c] = true;
	for(int d=0; d<4; d++){
		int nr = r + roff[d], nc = c + coff[d];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
		if(visited[nr][nc] || map[r][c] != map[nr][nc]) continue;
		result += dfs(nr, nc);
	}
	return result;
}

int main(){
	scanf("%d %d\n", &M, &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
		getchar();
	}
	int a = 0, e = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!visited[i][j]){
				int temp = dfs(i, j);
				(map[i][j] == 'W' ? a : e) += temp * temp;
			}
		}
	}
	printf("%d %d\n", a, e);
}