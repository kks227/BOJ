#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
const int INF = 1e9;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};
typedef pair<int, int> P;

int main(){
	int R, C, sr, sc, er, ec, W[500][500][4];
	char map[500][500];
	scanf("%d %d", &R, &C);
	queue<int> Q;
	bool visited[500][500] = {false};
	int dist[500][500], wd[500][500] = {0};
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'C'){ sr = i; sc = j; }
			else if(map[i][j] == 'F'){ er = i; ec = j; }
			else if(map[i][j] == '#'){ Q.push(i*1000 + j); visited[i][j] = true; }
			dist[i][j] = INF;
		}
	}
	for(int i=-1; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int r = Q.front()/1000, c = Q.front()%1000; Q.pop();
			wd[r][c] = i;
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
				if(!visited[nr][nc]){
					visited[nr][nc] = true;
					Q.push(nr*1000 + nc);
				}
			}
		}
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] != '#') continue;
			for(int d=0; d<4; d++){
				int rd = (d+2)%4;
				for(int k=1; ; k++){
					int nr = i+roff[d]*k, nc = j+coff[d]*k;
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') break;
					W[nr][nc][rd] = k-1;
				}
			}
		}
	}

	memset(visited, false, sizeof(visited));
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, sr*1000 + sc));
	dist[sr][sc] = 0;
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second/1000;
			c = PQ.top().second%1000;
			PQ.pop();
		}while(visited[r][c] && !PQ.empty());
		if(visited[r][c]) break;
		visited[r][c] = true;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(map[nr][nc] != '#'){
				int nd = dist[r][c] + 1;
				if(nd < dist[nr][nc]){
					dist[nr][nc] = nd;
					PQ.push(P(nd, nr*1000 + nc));
				}

				nr = r+roff[d]*W[r][c][d];
				nc = c+coff[d]*W[r][c][d];
				nd = dist[r][c] + wd[r][c] + 1;
				if(nd < dist[nr][nc]){
					dist[nr][nc] = nd;
					PQ.push(P(nd, nr*1000 + nc));
				}
			}
		}
	}
	if(!visited[er][ec]) puts("nemoguce");
	else printf("%d\n", dist[er][ec]);
}