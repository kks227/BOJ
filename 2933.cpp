#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char map[100][100];
bool visited[100][100];
int R, C;
const char roff[4] = {-1, 0, 1, 0};
const char coff[4] = {0, -1, 0, 1};

void DFS(int r, int c){
	visited[r][c] = true;
	for(int d=0; d<4; d++){
		int nr = r + roff[d];
		int nc = c + coff[d];
		if(nr<0 || nr>=R || nc<0 || nc>=C) continue;
		if(map[nr][nc]=='x' && !visited[nr][nc]) DFS(nr, nc);
	}
}

int main(){
	int N, H[100];
	scanf("%d %d\n", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
		getchar();
	}
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", H+i);

	for(int k=0; k<N; k++){
		bool hit = false;
		if(k%2){
			for(int i=C-1; i>=0; i--)
				if(map[R-H[k]][i] == 'x'){
					map[R-H[k]][i] = '.';
					hit = true;
					break;
				}
		}
		else{
			for(int i=0; i<C; i++)
				if(map[R-H[k]][i] == 'x'){
					map[R-H[k]][i] = '.';
					hit = true;
					break;
				}
		}
		if(!hit) continue;

		memset(visited, 0, sizeof(visited));
		for(int i=0; i<C; i++)
			if(!visited[R-1][i] && map[R-1][i]=='x')
				DFS(R-1, i);
		bool air[100][100] = {0};
		int fallH = R;
		bool fall = false;
		for(int j=0; j<C; j++){
			bool firstOnThisColumn = true;
			for(int i=R-2; i>=0; i--)
				if(map[i][j]=='x' && !visited[i][j]){
					air[i][j] = true;
					if(firstOnThisColumn){
						firstOnThisColumn = false;
						fall = true;
						int curH = 1;
						for(int h=i+2; h<R; h++){
							if(map[h][j] == 'x') break;
							curH++;
						}
						fallH = min(fallH, curH);
					}
				}
		}
		if(!fall) continue;

		for(int i=R-1; i>=0; i--)
			for(int j=0; j<C; j++)
				if(air[i][j]){
					map[i+fallH][j] = 'x';
					map[i][j] = '.';
				}
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			putchar(map[i][j]);
		puts("");
	}
}