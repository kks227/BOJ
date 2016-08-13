#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> Edge;

int main(){
	int N, M, K;
	vector<Edge> adj[100];
	int jewel[100];
	fill(jewel, jewel+100, -1);
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<K; i++){
		int k;
		scanf("%d", &k);
		jewel[k-1] = i;
	}
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		adj[a].push_back(Edge(b, c));
		adj[b].push_back(Edge(a, c));
	}

	bool visited[100*(1<<14)] = {1,};
	queue<int> Q;
	Q.push(0);
	int result[100] = {0};
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		int jcnt = curr / (100*(1<<14));
		int n = curr % (100*(1<<14)) / (1<<14);
		int has = curr % (100*(1<<14)) % (1<<14);
		result[n] = max(result[n], jcnt);
		
		if(jewel[n] != -1 && !(has & 1<<jewel[n])){
			int next = n*(1<<14) + (has | 1<<jewel[n]);
			visited[next] = true;
			Q.push(next + (jcnt+1)*100*(1<<14));
		}
		for(auto &e: adj[n]){
			int m = e.first;
			int k = e.second;
			if(k >= jcnt){
				int next = m*(1<<14) + has;
				if(!visited[next]){
					visited[next] = true;
					Q.push(next + jcnt*100*(1<<14));
				}
			}
		}
	}
	printf("%d\n", result[0]);
}