#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int R, C, H[52][52] = {0}, dist[52][52] = {0};
	scanf("%d %d", &R, &C);
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
			scanf("%1d", &H[i][j]);
	R += 2; C += 2;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			dist[i][j] = INF;
	dist[0][0] = 0;

	bool visited[52][52] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second/100;
			c = PQ.top().second%100;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(visited[r][c]) break;
		visited[r][c] = true;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
			if(dist[nr][nc] > max(dist[r][c], H[nr][nc])){
				dist[nr][nc] = max(dist[r][c], H[nr][nc]);
				PQ.push(P(dist[nr][nc], nr*100+nc));
			}
		}
	}

	int result = 0;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			result += dist[i][j] - H[i][j];
	printf("%d\n", result);
}