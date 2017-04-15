#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int C, R;
	char map[1000][1000];
	scanf("%d %d", &R, &C);
	bool visited[1000][1000] = {0};
	queue<int> Q, FQ;
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'J'){
				visited[i][j] = true;
				Q.push(i*1000 + j);
			}
			else if(map[i][j] == 'F')
				FQ.push(i*1000 + j);
		}
	}

	for(int result=1; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/1000, c = Q.front()%1000;
			Q.pop();
			if(map[r][c] == 'F') continue;
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C){
					printf("%d\n", result);
					return 0;
				}
				if(map[nr][nc] == '.' && !visited[nr][nc]){
					visited[nr][nc] = true;
					Q.push(nr*1000 + nc);
				}
			}
		}

		qSize = FQ.size();
		for(int i=0; i<qSize; i++){
			int r = FQ.front()/1000, c = FQ.front()%1000;
			FQ.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(map[nr][nc] == '.'){
					map[nr][nc] = 'F';
					FQ.push(nr*1000 + nc);
				}
			}
		}
	}
	puts("IMPOSSIBLE");
}