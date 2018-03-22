#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, K, sr, sc;
	scanf("%d %d %d", &R, &C, &K);
	char map[1000][1000];
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'S'){
				sr = i;
				sc = j;
			}
		}
	}

	queue<int> Q;
	bool visited[9][1000][1000] = {false,};
	Q.push(sr*1000 + sc);
	visited[0][sr][sc] = true;
	for(int result = 1; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int k = Q.front()/1000000;
			int r = Q.front()%1000000/1000;
			int c = Q.front()%1000;
			Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'X') continue;
				int nk = k;
				if(map[nr][nc] == k+1+'0') nk++;
				if(nk == K){
					printf("%d\n", result);
					return 0;
				}
				if(!visited[nk][nr][nc]){
					visited[nk][nr][nc] = true;
					Q.push(nk*1000000 + nr*1000 + nc);
				}
			}
		}
	}
}