#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
const int INF = 1e9;
const int MAX = 3600;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, D, val[16];
		scanf("%d %d", &N, &D);
		for(int i=0; i<N; i++)
			scanf("%d", val+i);

		int dist[MAX+1];
		fill(dist, dist+MAX+1, INF);
		dist[0] = 0;
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int i=0; i<N; i++){
				int next = min(max(curr+val[i], 0), MAX);
				if(dist[next] == INF){
					dist[next] = dist[curr] + 1;
					Q.push(next);
				}
			}
		}
		for(int i=D; i<=MAX; i++){
			if(dist[i] < INF){
				printf("%d %d\n", dist[i], i-D);
				break;
			}
		}
	}
}