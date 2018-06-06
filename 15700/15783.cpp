#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, SN, dfsn[100000], dcnt, sn[100000];
vector<int> adj[100000];
stack<int> S;
bool finished[100000];

int dfs(int curr){
	int result = dfsn[curr] = ++dcnt;
	S.push(curr);
	for(int next: adj[curr]){
		if(!dfsn[next]) result = min(dfs(next), result);
		else if(!finished[next]) result = min(dfsn[next], result);
	}
	if(result == dfsn[curr]){
		while(1){
			int s = S.top();
			S.pop();
			sn[s] = SN;
			finished[s] = true;
			if(s == curr) break;
		}
		SN++;
	}
	return result;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	for(int i=0; i<N; i++)
		if(!dfsn[i]) dfs(i);

	int result = 0, sd[100000] = {0};
	for(int i=0; i<N; i++)
		for(int j: adj[i])
			if(sn[i] != sn[j]) sd[sn[j]]++;
	for(int i=0; i<SN; i++)
		if(sd[i] == 0) result++;
	printf("%d\n", result);
}