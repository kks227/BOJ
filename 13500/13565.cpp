#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C;
	bool map[1000][1000], visited[1000][1000] = {0}, result = false;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%1d", &map[i][j]);
	queue<int> Q;
	for(int j=0; j<C; j++){
		if(!map[0][j]){
			visited[0][j] = true;
			Q.push(j);
		}
	}
	while(!Q.empty()){
		int r = Q.front()/1000, c = Q.front()%1000;
		Q.pop();
		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc]) continue;
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				Q.push(nr*1000 + nc);
			}
		}
	}
	for(int j=0; j<C; j++)
		if(visited[R-1][j]) result = true;
	puts(result ? "YES" : "NO");
}