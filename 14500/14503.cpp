#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const int nd[4] = {3, 0, 1, 2};

int main(){
	int R, C, r, c, d;
	bool map[50][50] = {0}, visited[50][50] = {0};
	scanf("%d %d %d %d %d", &R, &C, &r, &c, &d);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);

	while(1){
		visited[r][c] = true;

		bool fail = true, possible[4] = {0};
		for(int dd=0; dd<4; dd++){
			int nr = r+roff[dd], nc = c+coff[dd];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc]) continue;
			possible[dd] = true;
			if(!visited[nr][nc]){
				fail = false;
				break;
			}
		}
		if(fail){
			if(!possible[(d+2)%4]) break;
			r -= roff[d];
			c -= coff[d];
		}
		else{
			int nr = r+roff[nd[d]], nc = c+coff[nd[d]];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] || visited[nr][nc]) d = nd[d];
			else{
				r = nr;
				c = nc;
				d = nd[d];
			}
		}
	}

	int result = 0;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(visited[i][j]) result++;
	printf("%d\n", result);
}