#include <cstdio>
#include <queue>
using namespace std;

const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, sr, sc, er, ec;
	char map[50][50];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'S'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == 'D'){
				er = i;
				ec = j;
			}
		}
	}

	bool visited[50][50] = {0};
	visited[sr][sc] = true;
	queue<int> Q;
	Q.push(sr*100 + sc);
	int result = 0;
	while(!Q.empty() && !visited[er][ec]){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/100;
			int c = Q.front()%100;
			Q.pop();
			if(map[r][c] == '*') continue;

			for(int d=0; d<4; d++){
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(nr<0 || nr>=R || nc<0 || nc>=C || visited[nr][nc] || map[nr][nc]=='X') continue;
				if(map[nr][nc]=='.' || map[nr][nc]=='D'){
					visited[nr][nc] = true;
					Q.push(nr*100 + nc);
				}
			}
		}
		result++;

		bool water[50][50] = {0};
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++){
				if(map[i][j] != '*') continue;
				for(int d=0; d<4; d++){
					int ni = i+roff[d];
					int nj = j+coff[d];
					if(ni>=0 && ni<R && nj>=0 && nj<C) water[ni][nj] = true;
				}
			}
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				if(water[i][j] && map[i][j]!='D' && map[i][j]!='X')
					map[i][j] = '*';
	}
	if(visited[er][ec]) printf("%d\n", result);
	else puts("KAKTUS");
}