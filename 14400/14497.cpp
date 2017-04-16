#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, r[2], c[2];
	scanf("%d %d %d %d %d %d", &R, &C, r, c, r+1, c+1);
	r[0]--; r[1]--; c[0]--; c[1]--;
	char map[300][300];
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}
	for(int result=1; ; result++){
		bool visited[300][300] = {0};
		visited[r[0]][c[0]] = true;
		queue<int> Q;
		Q.push(r[0]*1000+c[0]);
		while(!Q.empty()){
			int r = Q.front()/1000, c = Q.front()%1000;
			Q.pop();
			if(map[r][c] == '1' || map[r][c] == '#') continue;

			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
				visited[nr][nc] = true;
				Q.push(nr*1000+nc);
			}
		}
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				if(visited[i][j]) map[i][j] = '0';

		if(map[r[1]][c[1]] == '0'){
			printf("%d\n", result);
			break;
		}
	}
}