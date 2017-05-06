#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, A, B, K, sr, sc, dr, dc;
	bool map[500][500] = {0};
	scanf("%d %d %d %d %d", &R, &C, &A, &B, &K);
	for(int i=0; i<K; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = true;
	}
	scanf("%d %d %d %d", &sr, &sc, &dr, &dc);
	sr--; sc--; dr--; dc--;

	queue<int> Q;
	Q.push(sr*1000 + sc);
	bool visited[500][500] = {0};
	visited[sr][sc] = true;
	for(int result=0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int k=0; k<qSize; k++){
			int r = Q.front()/1000, c = Q.front()%1000;
			Q.pop();
			if(r == dr && c == dc){
				printf("%d\n", result);
				return 0;
			}
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr+A > R || nc < 0 || nc+B > C || visited[nr][nc]) continue;
				bool blocked = false;
				for(int i=0; i<A; i++){
					for(int j=0; j<B; j++){
						if(map[nr+i][nc+j]){
							blocked = true;
							break;
						}
					}
					if(blocked) break;
				}
				visited[nr][nc] = true;
				if(!blocked) Q.push(nr*1000 + nc);
			}
		}
	}
	puts("-1");
}