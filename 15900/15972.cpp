#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, M, H, d[1000][1000][4];
	memset(d, -1, sizeof(d));
	scanf("%d %d %d", &N, &M, &H);
	for(int i=0; i<N+1; i++){
		for(int j=0; j<M; j++){
			int val;
			scanf("%d", &val);
			if(i > 0) d[i-1][j][1] = val;
			if(i < N) d[i][j][0] = val;
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M+1; j++){
			int val;
			scanf("%d", &val);
			if(j > 0) d[i][j-1][3] = val;
			if(j < M) d[i][j][2] = val;
		}
	}

	int dist[1000][1000];
	bool visited[1000][1000] = {false};
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			dist[i][j] = H;
			for(int k=0; k<4; k++){
				int nr = i+roff[k], nc = j+coff[k];
				if(d[i][j][k] >= 0 && (nr < 0 || nr >= N || nc < 0 || nc >= M)){
					dist[i][j] = min(d[i][j][k], dist[i][j]);
					PQ.push(P(dist[i][j], i*1000+j));
				}
			}
		}
	}

	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second/1000, c = PQ.top().second%1000;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(visited[r][c]) break;
		visited[r][c] = true;

		for(int k=0; k<4; k++){
			int nr = r+roff[k], nc = c+coff[k];
			if(d[r][c][k] < 0 || nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
			int nd = max(dist[r][c], d[r][c][k]);
			if(nd < dist[nr][nc]){
				dist[nr][nc] = nd;
				PQ.push(P(dist[nr][nc], nr*1000+nc));
			}
		}
	}

	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			result += dist[i][j];
	printf("%d\n", result);
}