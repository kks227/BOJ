#include <cstdio>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, K, r, c, D[4], d = 0;
	bool visited[1000][1000] = {0};
	scanf("%d %d %d", &R, &C, &K);
	for(int i=0; i<K; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		visited[r][c] = true;
	}
	scanf("%d %d", &r, &c);
	visited[r][c] = true;
	for(int i=0; i<4; i++){
		scanf("%d", D+i);
		D[i]--;
	}
	
	while(1){
		int nr = r+roff[D[d]], nc = c+coff[D[d]];
		if(nr<0 || nr>=R || nc<0 || nc>=C || visited[nr][nc]){
			int k;
			for(k=1; k<4; k++){
				d = (d+1)%4;
				nr = r+roff[D[d]]; nc = c+coff[D[d]];
				if(nr>=0 && nr<R && nc>=0 && nc<C && !visited[nr][nc]) break;
			}
			if(k == 4) break;
		}
		visited[nr][nc] = true;
		r = nr;
		c = nc;
	}
	printf("%d %d\n", r, c);
}