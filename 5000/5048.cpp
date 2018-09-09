#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, sr, sc, map[50][50];
	scanf("%d %d", &C, &R);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'P'){
				sr = i;
				sc = j;
			}
		}
	}

	bool visited[50][50] = {false};
	visited[sr][sc] = true;
	int result = 0;
	queue<int> Q;
	Q.push(sr*50 + sc);
	while(!Q.empty()){
		int r = Q.front()/50, c = Q.front()%50;
		Q.pop();
		if(map[r][c] == 'G') result++;
		int tcnt = 0;
		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(map[nr][nc] == 'T') tcnt++;
		}
		if(tcnt > 0) continue;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(map[nr][nc] != '#' && !visited[nr][nc]){
				visited[nr][nc] = true;
				Q.push(nr*50 + nc);
			}
		}
	}
	printf("%d\n", result);
}