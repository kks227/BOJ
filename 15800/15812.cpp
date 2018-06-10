#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, result = INF;
	bool map[20][20];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%1d", &map[i][j]);
	for(int k1=0; k1<R*C-1; k1++){
		int r1 = k1/C, c1 = k1%C;
		if(map[r1][c1]) continue;
		for(int k2=k1+1; k2<R*C; k2++){
			int r2 = k2/C, c2 = k2%C;
			if(map[r2][c2]) continue;

			queue<int> Q;
			int dist[20][20], temp = 0;
			for(int i=0; i<20; i++)
				fill(dist[i], dist[i]+20, INF);
			Q.push(r1*20 + c1);
			Q.push(r2*20 + c2);
			dist[r1][c1] = dist[r2][c2] = 0;
			while(!Q.empty()){
				int r = Q.front()/20, c = Q.front()%20;
				Q.pop();
				for(int d=0; d<4; d++){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
					if(dist[nr][nc] == INF){
						dist[nr][nc] = dist[r][c] + 1;
						Q.push(nr*20 + nc);
						if(map[nr][nc]) temp = max(temp, dist[nr][nc]);
					}
				}
			}
			result = min(temp, result);
		}
	}
	printf("%d\n", result);
}