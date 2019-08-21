#include <cstdio>
using namespace std;
const int MAX = 100;
const int roff[4] = {1, 0, -1, 0};
const int coff[4] = {0, 1, 0, -1};

int main(){
	int R, C, d = 0, r = 0, c = 0, result = 0;
	bool visited[MAX][MAX] = {false,};
	scanf("%d %d", &C, &R);
	for(int i = 0; i < R*C; ++i){
		visited[r][c] = true;
		int nr = r+roff[d], nc = c+coff[d];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]){
			if(i == R*C-1) break;
			d = (d+1)%4;
			r = r+roff[d];
			c = c+coff[d];
			++result;
		}
		else{
			r = nr;
			c = nc;
		}
	}
	printf("%d\n", result);
}