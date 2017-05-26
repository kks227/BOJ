#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, dr[2], dc[2], dcnt = 0, dist[50][50][4];
	char map[50][50];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++){
			map[i][j] = getchar();
			if(map[i][j] == '#'){
				dr[dcnt] = i;
				dc[dcnt++] = j;
			}
			for(int k=0; k<4; k++)
				dist[i][j][k] = INF;
		}
	}

	bool visited[50][50][4] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int d=0; d<4; d++){
		dist[dr[0]][dc[0]][d] = 0;
		PQ.push({0, d*2500 + dr[0]*50 + dc[0]});
	}
	while(!PQ.empty()){
		int r, c, d;
		do{
			c = PQ.top().second % 50;
			r = PQ.top().second % 2500 / 50;
			d = PQ.top().second / 2500;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c][d]);
		if(visited[r][c][d]) break;

		visited[r][c][d] = true;
		for(int k=-1; k<=1; k++){
			if(k != 0 && map[r][c] != '!') continue;

			int nd = (d+k+4)%4, nr = r+roff[nd], nc = c+coff[nd];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == '*') continue;
			if(dist[nr][nc][nd] > dist[r][c][d] + !!k){
				dist[nr][nc][nd] = dist[r][c][d] + !!k;
				PQ.push({dist[nr][nc][nd], nd*2500 + nr*50 + nc});
			}
		}
	}

	int result = INF;
	for(int d=0; d<4; d++)
		result = min(result, dist[dr[1]][dc[1]][d]);
	printf("%d\n", result);
}