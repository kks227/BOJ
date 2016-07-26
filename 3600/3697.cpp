#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct Pos{
	int h, r, c;
	Pos(): Pos(0, -1, -1){}
	Pos(int r1, int c1, int h1): r(r1), c(c1), h(h1){}
	bool operator <(const Pos& A){ return h < A.h; }
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, D, h[500][500];
		scanf("%d %d %d", &N, &M, &D);
		Pos pos[250000];
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				scanf("%d", &h[i][j]);
				pos[i*M+j] = Pos(i, j, h[i][j]);
			}
		}
		sort(pos, pos+N*M);

		int result = 0;
		int visited[500][500] = {0};
		for(int i=N*M-1; i>=0; i--){
			int sr = pos[i].r;
			int sc = pos[i].c;
			if(visited[sr][sc] > 0) continue;

			visited[sr][sc] = i+1;
			int cnt = 0;
			bool fail = false;
			queue<int> Q;
			Q.push(sr*500 + sc);
			while(!Q.empty()){
				int r = Q.front()/500;
				int c = Q.front()%500;
				Q.pop();
				if(h[r][c] == h[sr][sc]) cnt++;

				for(int d=0; d<4; d++){
					int nr = r+roff[d];
					int nc = c+coff[d];
					if(nr<0 || nr>=N || nc<0 || nc>=M || visited[nr][nc]==i+1) continue;
					if(visited[nr][nc] > i+1){
						fail = true;
						break;
					}
					if(h[nr][nc] <= h[sr][sc]-D) continue;
					visited[nr][nc] = i+1;
					Q.push(nr*500 + nc);
				}
				if(fail) break;
			}
			if(!fail) result += cnt;
		}
		printf("%d\n", result);
	}
}