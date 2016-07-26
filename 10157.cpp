#include <cstdio>
using namespace std;

const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};

int main(){
	int C, R, K;
	scanf("%d %d %d", &C, &R, &K);
	if(K > C*R){
		puts("0");
		return 0;
	}
	int d = 0, r = R-1, c = 0;
	bool visited[1000][1000] = {0};
	for(int i=1; i<K; i++){
		visited[r][c] = true;
		int nr = r+roff[d];
		int nc = c+coff[d];
		if(nr<0 || nr>=R || nc<0 || nc>=C || visited[nr][nc]){
			d = (d+1)%4;
			nr = r+roff[d];
			nc = c+coff[d];
		}
		r = nr;
		c = nc;
	}
	printf("%d %d\n", c+1, R-r);
}