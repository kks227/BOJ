#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct Edge{
	int u, v, w;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge& A){ return w < A.w; }
};

int uf[251];

int uf_find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = uf_find(uf[n]);
}

bool uf_union(int n, int m){
	n = uf_find(n);
	m = uf_find(m);
	if(n == m) return false;
	uf[m] = n;
	return true;
}



int main(){
	int N, M, cnt = 0, pn[50][50];
	scanf("%d %d", &N, &M);
	char map[50][50];
	P pos[251];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'S') map[i][j] = 'K';
			if(map[i][j] == 'K'){
				pn[i][j] = cnt;
				pos[cnt++] = P(i, j);
			}
			else pn[i][j] = -1;
		}
	}
	M++;

	int dist[251][251];
	for(int i=0; i<M; i++){
		fill(dist[i], dist[i]+M, INF);
		dist[i][i] = 0;
	}
	for(int i=0; i<M; i++){
		queue<P> Q;
		Q.push(pos[i]);
		bool visited[251][251] = {0};
		visited[pos[i].first][pos[i].second] = true;

		int dcnt = 0;
		while(!Q.empty()){
			int qSize = Q.size();
			for(int j=0; j<qSize; j++){
				int r = Q.front().first;
				int c = Q.front().second;
				Q.pop();
				if(map[r][c] == 'K') dist[i][pn[r][c]] = min(dist[i][pn[r][c]], dcnt);

				for(int d=0; d<4; d++){
					int nr = r+roff[d];
					int nc = c+coff[d];
					if(nr<0 || nr>=N || nc<0 || nc>=N || map[nr][nc]=='1' || visited[nr][nc]) continue;
					visited[nr][nc] = true;
					Q.push(P(nr, nc));
				}
			}
			dcnt++;
		}
	}
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++)
			if(dist[i][j] == INF){
				puts("-1");
				return 0;
			}

	Edge edge[251*251];
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++)
			edge[i*M+j] = Edge(i, j, dist[i][j]);
	sort(edge, edge+M*M);

	fill(uf, uf+M, -1);
	int ucnt = 0, result = 0;
	for(int i=0; i<M*M && ucnt<M-1; i++){
		if(uf_union(edge[i].u, edge[i].v)){
			ucnt++;
			result += edge[i].w;
		}
	}
	printf("%d\n", result);
}