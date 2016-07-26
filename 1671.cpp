#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N, flow[2002][2002];
vector<int> adj[2002];

void makeEdge(int start, int dest, int weight){
	adj[start].push_back(dest);
	adj[dest].push_back(start);
	flow[start][dest] += weight;
}

int main(){
	int val[1000][3];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &val[i][j]);

	// source: 2N, sink: 2N+1
	for(int i=0; i<N; i++){
		// source, sink
		makeEdge(2*N, 2*i, 2);
		makeEdge(2*i+1, 2*N+1, 1);

		// shark to shark
		for(int j=0; j<N; j++){
			if(i==j) continue;
			if(val[i][0]<val[j][0] || val[i][1]<val[j][1] || val[i][2]<val[j][2]) continue;
			if(val[i][0]==val[j][0] && val[i][1]==val[j][1] && val[i][2]==val[j][2] && i>j) continue;
			makeEdge(2*i, 2*j+1, 1);
		}
	}

	int result = N;
	while(1){
		int prev[2002];
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(2*N);
		while(!q.empty() && prev[2*N+1]==-1){
			int u = q.front();
			q.pop();
			for(int v: adj[u])
				if(flow[u][v]>0 && prev[v]==-1){
					q.push(v);
					prev[v] = u;
				}
		}
		if(prev[2*N+1] == -1) break;
		for(int u=2*N+1; u!=2*N; u=prev[u]){
			flow[prev[u]][u]--;
			flow[u][prev[u]]++;
		}
		result--;
	}
	printf("%d\n", result);
}