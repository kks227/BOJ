#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const int i2d[4] = {1, 3, 2, 0};
const int INF = 1e9;

struct Node{
	int r, c, d;
	Node(): Node(0, 0, 0){}
	Node(int r1, int c1, int d1): r(r1), c(c1), d(d1){}
	bool operator <(const Node &O)const{ // dummy
		if(r != O.r) return r < O.r;
		if(c != O.c) return c < O.c;
		return d < O.d;
	}
};

typedef pair<int, Node> P;

int main(){
	int R, C, sr, sc, sd, dr, dc, dd, dist[100][100][4];
	bool map[100][100], visited[100][100][4] = {0};
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &map[i][j]);
			for(int k=0; k<4; k++)
				dist[i][j][k] = INF;
		}
	}
	scanf("%d %d %d %d %d %d", &sr, &sc, &sd, &dr, &dc, &dd);
	sr--; sc--; dr--; dc--;
	sd = i2d[sd-1];
	dd = i2d[dd-1];

	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, Node(sr, sc, sd)));
	dist[sr][sc][sd] = 0;
	while(!PQ.empty()){
		int r, c, d;
		do{
			const Node &temp = PQ.top().second;
			r = temp.r;
			c = temp.c;
			d = temp.d;
			PQ.pop();
		}while(visited[r][c][d] && !PQ.empty());
		if(visited[r][c][d]) break;
		visited[r][c][d] = true;

		for(int j=0; j<=3; j++){
			int nr = r+roff[d]*j, nc = c+coff[d]*j;
			if(nr<0 || nr>=R || nc<0 || nc>=C || map[nr][nc]) break;
			for(int k=-1; k<=2; k++){
				int nd = (d+4+k) % 4;
				if(dist[nr][nc][nd] > dist[r][c][d] + abs(k) + !!j){
					dist[nr][nc][nd] = dist[r][c][d] + abs(k) + !!j;
					PQ.push(P(dist[nr][nc][nd], Node(nr, nc, nd)));
				}
			}
		}
	}
	printf("%d\n", dist[dr][dc][dd]);
}