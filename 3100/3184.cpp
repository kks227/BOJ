#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C;
	char map[250][250];
	scanf("%d %d\n", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
		getchar();
	}

	bool visited[250][250] = {0};
	int r1 = 0, r2 = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(visited[i][j] || map[i][j] == '#') continue;

			queue<int> Q;
			Q.push(i*C + j);
			visited[i][j] = true;
			int scnt = 0, wcnt = 0;
			while(!Q.empty()){
				int r = Q.front()/C, c = Q.front()%C;
				Q.pop();
				if(map[r][c] == 'o') scnt++;
				else if(map[r][c] == 'v') wcnt++;

				for(int d=0; d<4; d++){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*C + nc);
					}
				}
			}

			if(scnt > wcnt) r1 += scnt;
			else r2 += wcnt;
		}
	}
	printf("%d %d\n", r1, r2);
}