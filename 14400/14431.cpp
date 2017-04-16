#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int P_MAX = 10000;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, x[4002], y[4002];
	scanf("%d %d %d %d %d", x, y, x+1, y+1, &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", x+2+i, y+2+i);
	N += 2;

	bool np[P_MAX] = {1, 1};
	for(int i=4; i<P_MAX; i+=2)
		np[i] = true;
	for(int i=3; i<P_MAX; i+=2){
		if(np[i]) continue;
		for(int j=i*i; j<P_MAX; j+=i*2)
			np[j] = true;
	}
	vector<P> adj[4002];
	for(int i=1; i<N; i++){
		for(int j=0; j<i; j++){
			int d = sqrt(pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0));
			if(!np[d]){
				adj[i].push_back({j, d});
				adj[j].push_back({i, d});
			}
		}
	}

	int dist[4002];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	bool visited[4002] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push({0, 0});
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;

		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push({dist[next], next});
			}
		}
	}
	printf("%d\n", visited[1] ? dist[1] : -1);
}