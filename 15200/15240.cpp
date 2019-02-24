#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, sr, sc, col1, col2, map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%1d", &map[i][j]);
	scanf("%d %d %d", &sr, &sc, &col2);
	col1 = map[sr][sc];
	if(col1 != col2){
		queue<int> Q;
		Q.push(sr*MAX + sc);
		map[sr][sc] = col2;
		while(!Q.empty()){
			int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != col1) continue;
				Q.push(nr*MAX + nc);
				map[nr][nc] = col2;
			}
		}
	}

	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j)
			printf("%d", map[i][j]);
		puts("");
	}
}