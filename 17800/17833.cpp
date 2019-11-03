#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 2000;
const int INF = 1e9 * 2 + 1;
typedef pair<int, int> P;

int main(){
	int N, M, R, D, H[MAX], T[MAX], E[MAX][2], dist[MAX];
	scanf("%d %d %d %d", &N, &R, &D, &M);
	--R; --D;
	fill(dist, dist+N, INF);
	dist[R] = 0;
	for(int i = 0; i < M; ++i){
		scanf("%d %d %d %d", H+i, T+i, &E[i][0], &E[i][1]);
		--E[i][0]; --E[i][1];
	}

	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, R));
	bool visited[MAX] = {false,};
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;

		for(int i = 0; i < M; ++i){
			for(int j = 0; j < 2; ++j){
				if(curr - E[i][j] + H[i] > N || curr - E[i][j] < 0) continue;
				int next = curr - E[i][j] + E[i][!j], d = dist[curr] + T[i];
				if(dist[next] > d){
					dist[next] = d;
					PQ.push(P(d, next));
				}
			}
		}
	}

	if(dist[D] == INF) puts("-1");
	else printf("%d\n", dist[D]);
}