#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX = 302;
const int INF = 1e9 + 1;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int R, C, H[MAX][MAX] = {0,};
	scanf("%d %d", &C, &R);
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j)
			scanf("%d", &H[i][j]);
	R += 2; C += 2;

	int dist[MAX][MAX];
	for(int i = 0; i < R; ++i)
		fill(dist[i], dist[i]+C, INF);
	dist[0][0] = 0;
	bool visited[MAX][MAX] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second / MAX;
			c = PQ.top().second % MAX;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(visited[r][c]) break;
		visited[r][c] = true;

		for(int d = 0; d < 4; ++d){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			int nd = max(dist[r][c], H[nr][nc]);
			if(dist[nr][nc] > nd){
				dist[nr][nc] = nd;
				PQ.push(P(nd, nr*MAX + nc));
			}
		}
	}

	unsigned int result = 0;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			result += dist[i][j] - H[i][j];
	printf("%u\n", result);
}