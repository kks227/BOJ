#include <cstdio>
using namespace std;
const char DIR[4] = {'U', 'R', 'D', 'L'};
const int ls[4] = {1, 0, 3, 2}; // '/'
const int rs[4] = {3, 2, 1, 0}; // '\'
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const int INF = 1000000000;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	char map[500][500];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
	}
	int PR, PC;
	scanf("%d %d", &PR, &PC);
	PR--; PC--;

	int val = -1;
	char result;
	for(int i=0; i<4; i++){
		int cnt = 0, r = PR, c = PC, d = i;
		bool visited[500][500][4] = {0};
		while(1){
			if(visited[r][c][d]){
				cnt = INF;
				break;
			}
			visited[r][c][d] = true;
			cnt++;
			int nr = r+roff[d];
			int nc = c+coff[d];
			if(nr<0 || nr>=N || nc<0 || nc>=M || map[nr][nc]=='C') break;
			if(map[nr][nc] == '/') d = ls[d];
			else if(map[nr][nc] == '\\') d = rs[d];
			r = nr;
			c = nc;
		}
		if(val < cnt){
			val = cnt;
			result = DIR[i];
		}
	}
	printf("%c\n", result);
	if(val < INF) printf("%d\n", val);
	else puts("Voyager");
}