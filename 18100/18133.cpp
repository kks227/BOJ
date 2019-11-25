#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int cnt, dfsn[MAX], SN, sn[MAX];
bool finished[MAX];
vector<int> adj[MAX];
stack<int> S;

int dfs(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		while(1){
			int t = S.top();
			S.pop();
			sn[t] = SN;
			finished[t] = true;
			if(t == curr) break;
		}
		++SN;
	}
	return result;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u-1].push_back(v-1);
		}

		cnt = SN = 0;
		fill(dfsn, dfsn+N, 0);
		fill(sn, sn+N, 0);
		fill(finished, finished+N, false);
		for(int i = 0; i < N; ++i)
			if(dfsn[i] == 0) dfs(i);

		int sIndegree[MAX] = {0};
		for(int i = 0; i < N; ++i)
			for(int j: adj[i])
				if(sn[i] != sn[j]) ++sIndegree[sn[j]];
		int result = 0;
		for(int i = 0; i < SN; ++i)
			if(sIndegree[i] == 0) ++result;
		printf("%d\n", result);

		for(int i = 0; i < N; ++i)
			adj[i].clear();
	}
}