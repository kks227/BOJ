#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, SN, sn[5000], cnt, dfsn[5000];
bool finished[5000], sOut[5000];
vector<int> adj[5000];
stack<int> S;

int dfs(int curr){
	int result = dfsn[curr] = ++cnt;
	S.push(curr);
	for(int next: adj[curr]){
		if(finished[next]);
		else if(dfsn[next]) result = min(result, dfsn[next]);
		else result = min(result, dfs(next));
	}

	if(result == dfsn[curr]){
		while(1){
			int v = S.top();
			S.pop();
			sn[v] = SN;
			finished[v] = true;
			if(v == curr) break;
		}
		SN++;
	}
	return result;
}

int main(){
	while(1){
		scanf("%d", &V);
		if(V == 0) break;

		scanf("%d", &E);
		SN = cnt = 0;
		for(int i=0; i<V; i++){
			adj[i].clear();
			dfsn[i] = finished[i] = sOut[i] = 0;
		}
		for(int i=0; i<E; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u-1].push_back(v-1);
		}

		for(int i=0; i<V; i++)
			if(dfsn[i] == 0) dfs(i);
		for(int i=0; i<V; i++)
			for(int j: adj[i])
				if(sn[i] != sn[j]) sOut[sn[i]] = true;
		for(int i=0; i<V; i++)
			if(!sOut[sn[i]]) printf("%d ", i+1);
		puts("");
	}
}