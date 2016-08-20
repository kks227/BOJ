#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> Edge;

int main(){
	int N, M, cnt[100][100] = {0}, pre[100] = {0};
	vector<Edge> adj[100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int X, Y, K;
		scanf("%d %d %d", &X, &Y, &K);
		X--; Y--;
		pre[X]++;
		adj[Y].push_back(Edge(X, K));
	}
	queue<int> Q;
	vector<int> essential;
	for(int i=0; i<N; i++){
		if(pre[i] == 0){
			essential.push_back(i);
			cnt[i][i] = 1;
			Q.push(i);
		}
	}
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(auto &p: adj[curr]){
			int next = p.first, weight = p.second;
			for(int i: essential)
				cnt[next][i] += cnt[curr][i] * weight;
			if(--pre[next] == 0) Q.push(next);
		}
	}
	for(int i: essential)
		printf("%d %d\n", i+1, cnt[N-1][i]);
}