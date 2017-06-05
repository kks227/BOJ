#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int main(){
	int N, S, E, d[1000][1000] = {0};
	char M[1000][101];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", M[i]);
		for(int j=0; j<i; j++){
			for(int k=0; M[i][k]; k++)
				d[i][j] += pow(abs(M[i][k]-M[j][k]), 2);
			d[j][i] = d[i][j];
		}
	}
	scanf("%d %d", &S, &E);
	S--; E--;

	int dist[1000];
	fill(dist, dist+N, INF);
	dist[S] = 0;
	bool visited[1000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, S));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;

		visited[curr] = true;
		for(int next=0; next<N; next++){
			if(dist[next] > dist[curr] + d[curr][next]){
				dist[next] = dist[curr] + d[curr][next];
				PQ.push(P(dist[next], next));
			}
		}
	}
	printf("%d\n", dist[E]);
}