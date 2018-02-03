#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int INF = 1e9;

int main(){
	int N, M, e[MAX*2][3], d[MAX];
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
		e[i][0]--; e[i][1]--;
		adj[e[i][0]].push_back(i);
		adj[e[i][1]].push_back(i);
	}
	fill(d, d+N, INF);
	d[N-1] = 0;

	queue<int> Q;
	Q.push(N-1);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int i: adj[curr]){
			int next = (curr != e[i][0] ? e[i][0] : e[i][1]);
			if(d[next] == INF){
				d[next] = d[curr] + 1;
				Q.push(next);
			}
		}
	}
	printf("%d\n", d[0]);

	bool visited[MAX] = {true};
	int V[MAX] = {0}, lo = 0, hi = 1;
	for(int i=0; i<d[0]; i++){
		int c = INF;
		for(int j=lo; j<hi; j++){
			int curr = V[j];
			for(int k: adj[curr]){
				int next = (curr != e[k][0] ? e[k][0] : e[k][1]);
				if(d[curr]-1 == d[next]) c = min(c, e[k][2]);
			}
		}
		printf("%d ", c);

		int old = hi;
		for(int j=lo; j<old; j++){
			int curr = V[j];
			for(int k: adj[curr]){
				int next = (curr != e[k][0] ? e[k][0] : e[k][1]);
				if(d[curr]-1 == d[next] && c == e[k][2] && !visited[next]){
					visited[next] = true;
					V[hi++] = next;
				}
			}
		}
		lo = old;
	}
}