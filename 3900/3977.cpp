#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int cnt, dfsn[100000], SN, sn[100000];
vector<int> adj[100000];
bool finished[100000];
stack<int> S;
vector<vector<int>> scc;

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		vector<int> newScc;
		while(1){
			int t = S.top();
			S.pop();
			sn[t] = SN;
			finished[t] = true;
			newScc.push_back(t);
			if(t == curr) break;
		}
		sort(newScc.begin(), newScc.end());
		scc.push_back(newScc);
		SN++;
	}
	return result;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
			adj[i].clear();
		for(int i=0; i<M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		cnt = SN = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, 0, sizeof(finished));
		scc.clear();
		for(int i=0; i<N; i++)
			if(dfsn[i] == 0) GetSCCsByDFS(i);

		int sIndegree[100000] = {0};
		for(int i=0; i<N; i++)
			for(int j: adj[i])
				if(sn[i] != sn[j]) sIndegree[sn[j]]++;
		int cnt = 0, start = -1;
		for(int i=0; i<SN; i++)
			if(sIndegree[i] == 0){
				cnt++;
				start = i;
			}
		if(cnt > 1) puts("Confused");
		else{
			for(int i: scc[start])
				printf("%d\n", i);
		}
		puts("");
	}
}