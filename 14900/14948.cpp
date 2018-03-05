#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, map[100][100];
	scanf("%d %d\n", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);

	int lo = -1, hi = 1e9;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		bool visited[100][100][2] = {true,};
		queue<int> Q;
		if(mid >= map[0][0]) Q.push(0);
		while(!Q.empty()){
			int r = Q.front()%10000/100, c = Q.front()%100;
			bool u = Q.front()/10000; Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(mid >= map[nr][nc]){
					if(!visited[nr][nc][u]){
						visited[nr][nc][u] = true;
						Q.push(u*10000 + nr*100 + nc);
					}
				}
				else if(!u){
					int nnr = nr+roff[d], nnc = nc+coff[d];
					if(nnr < 0 || nnr >= R || nnc < 0 || nnc >= C || mid < map[nnr][nnc]) continue;
					if(!visited[nnr][nnc][true]){
						visited[nnr][nnc][true] = true;
						Q.push(10000 + nnr*100 + nnc);
					}
				}
			}
		}
		bool result = false;
		(visited[R-1][C-1][0] || visited[R-1][C-1][1] ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}