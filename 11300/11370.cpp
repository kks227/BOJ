#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 10;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
	while(1){
		int R, C, sr, sc, er, ec;
		scanf("%d %d", &C, &R);
		if(C == 0) break;

		char map[MAX][MAX];
		queue<int> Q;
		for(int i = 0; i < R; ++i){
			getchar();
			for(int j = 0; j < C; ++j){
				map[i][j] = getchar();
				if(map[i][j] == 'S') Q.push(i*MAX + j);
			}
		}

		while(!Q.empty()){
			int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 'T') continue;
				map[nr][nc] = 'S';
				Q.push(nr*MAX + nc);
			}
		}
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j)
				putchar(map[i][j]);
			puts("");
		}
	}
}