#include <cstdio>
using namespace std;
const int S = 6;
const char pc[2] = {'B', 'W'};
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int N;
	scanf("%d", &N);
	char map[S][S];
	for(int i=0; i<S; i++)
		for(int j=0; j<S; j++)
			map[i][j] = '.';
	map[2][2] = map[3][3] = 'W';
	map[2][3] = map[3][2] = 'B';

	for(int i=0; i<N; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		r--; c--;
		bool t = i%2;

		map[r][c] = pc[t];
		for(int d=0; d<8; d++){
			int cnt = 0;
			for(int k=1; ; k++){
				int nr = r+roff[d]*k, nc = c+coff[d]*k;
				if(nr < 0 || nr >= S || nc < 0 || nc >= S || map[nr][nc] == '.'){
					cnt = 0;
					break;
				}
				if(map[nr][nc] == pc[t]) break;
				cnt++;
			}
			for(int k=1; k<=cnt; k++){
				int nr = r+roff[d]*k, nc = c+coff[d]*k;
				map[nr][nc] = pc[t];
			}
		}
	}

	int Bcnt = 0, Wcnt = 0;
	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
			putchar(map[i][j]);
			if(map[i][j] == 'B') Bcnt++;
			else if(map[i][j] == 'W') Wcnt++;
		}
		puts("");
	}
	puts(Bcnt > Wcnt ? "Black" : "White");
}