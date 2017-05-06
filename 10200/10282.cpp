#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, S;
		scanf("%d %d %d", &N, &M, &S);
		S--;
		vector<P> adj[10000];
		for(int i=0; i<M; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			adj[b].push_back(P(a, c));
		}

		int dist[10000], cnt = 0, result = 0;
		fill(dist, dist+N, INF);
		dist[S] = 0;
		bool visited[10000] = {0};
		priority_queue<P, vector<P>, greater<P>> PQ;
		PQ.push(P(0, S));

		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(!PQ.empty() && visited[curr]);
			if(visited[curr]) break;

			visited[curr] = true;
			cnt++;
			result = dist[curr];
			for(auto &p: adj[curr]){
				int next = p.first, d = p.second;
				if(dist[next] > dist[curr] + d){
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}
		printf("%d %d\n", cnt, result);
	}
}