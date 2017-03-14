#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX = 1500;

int uf[MAX*MAX];

int uf_find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = uf_find(uf[a]);
}

bool uf_union(int a, int b){
	a = uf_find(a);
	b = uf_find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}



int main(){
	int R, C, pos[2], cnt = 0;
	char map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'L') pos[cnt++] = i*MAX+j;
		}
	}

	fill(uf, uf+MAX*MAX, -1);
	queue<int> Q;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] == 'X') continue;
			for(int d=0; d<4; d++){
				int ii = i+roff[d], jj = j+coff[d];
				if(ii<0 || ii>=R || jj<0 || jj>=C || map[ii][jj]=='X') continue;
				uf_union(i*MAX+j, ii*MAX+jj);
			}
			Q.push(i*MAX+j);
		}
	}

	for(int result=0; ; result++){
		if(uf_find(pos[0]) == uf_find(pos[1])){
			printf("%d\n", result);
			break;
		}
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/MAX, c = Q.front()%MAX;
			Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr<0 || nr>=R || nc<0 || nc>=C || map[nr][nc]!='X') continue;
				map[nr][nc] = '.';
				uf_union(r*MAX+c, nr*MAX+nc);
				Q.push(nr*MAX+nc);
				for(int dd=0; dd<4; dd++){
					int nnr = nr+roff[dd], nnc = nc+coff[dd];
					if(nnr<0 || nnr>=R || nnc<0 || nnc>=C || map[nnr][nnc]=='X') continue;
					uf_union(nr*MAX+nc, nnr*MAX+nnc);
				}
			}
		}
	}
}