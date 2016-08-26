#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000; // 절대 나올 수 없는 경로값
typedef pair<int, int> P;

int main(){
	int V, E, K;
	vector<P> adj[MAX_V]; // (이어진 정점 번호, 거리)
	scanf("%d %d %d", &V, &E, &K);
	K--;
	for(int i=0; i<E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(P(v-1, w));
	}

	int dist[MAX_V];
	fill(dist, dist+MAX_V, INF);
	bool visited[MAX_V] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;

	// 다익스트라 알고리즘
	dist[K] = 0; // 시작점으로의 거리는 0
	PQ.push(P(0, K)); // 시작점만 PQ에 넣고 시작
	while(!PQ.empty()){ // PQ가 비면 종료
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]); // curr가 방문한 정점이면 무시
		// 더 이상 방문할 수 있는 정점이 없으면 종료
		if(visited[curr]) break;

		visited[curr] = true; // 방문
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			// 거리가 갱신될 경우 PQ에 새로 넣음
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	// 결과
	for(int i=0; i<V; i++){
		if(dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
}