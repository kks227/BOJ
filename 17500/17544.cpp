#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 1000;
const int MAX_VAL = 1e9;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int R, C, K, h[MAX][MAX];
	vector<int> hVals;
	scanf("%d %d %d", &R, &C, &K);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &h[i][j]);
			hVals.push_back(h[i][j]);
		}
	}
	hVals.push_back(MAX_VAL + 1);
	sort(hVals.begin(), hVals.end());
	hVals.resize(unique(hVals.begin(), hVals.end()) - hVals.begin());
	int lo = 0, hi = hVals.size();

	while(lo+1 < hi){
		int mid = (lo + hi) / 2;

		int dist[MAX][MAX];
		bool visited[MAX][MAX] = {false,};
		priority_queue<P, vector<P>, greater<P>> PQ;
		for(int i = 0; i < R-1; ++i)
			fill(dist[i], dist[i] + C, INF);
		for(int j = 0; j < C; ++j){
			dist[R-1][j] = (h[R-1][j] < hVals[mid] ? 1 : 0);
			PQ.push(P(dist[R-1][j], (R-1)*MAX + j));
		}

		int temp = INF;
		while(!PQ.empty()){
			int r, c;
			do{
				r = PQ.top().second / MAX;
				c = PQ.top().second % MAX;
				PQ.pop();
			}while(visited[r][c] && !PQ.empty());
			if(visited[r][c]) break;
			visited[r][c] = true;
			if(r == 0) temp = min(dist[r][c], temp);

			for(int d = 0; d < 4; ++d){
				int nr = r + roff[d], nc = c + coff[d], nd = dist[r][c];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(h[nr][nc] < hVals[mid]) ++nd;
				if(dist[nr][nc] > nd){
					dist[nr][nc] = nd;
					PQ.push(P(nd, nr*MAX + nc));
				}
			}
		}
		(temp <= K ? lo : hi) = mid;
	}
	printf("%d\n", hVals[lo]);
}