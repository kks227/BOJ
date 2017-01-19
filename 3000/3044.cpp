#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MOD = 1e9;

int N, M, SN, cnt, sn[10000], sSize[10000], dfsn[10000];
bool finished[10000];
vector<int> adj[10000];
stack<int> S;

int dfs(int curr){
	int result = dfsn[curr] = ++cnt;
	S.push(curr);
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result == dfsn[curr]){
		while(1){
			int n = S.top();
			S.pop();
			sn[n] = SN;
			finished[n] = true;
			sSize[SN]++;
			if(n == curr) break;
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
		adj[u-1].push_back(v-1);
	}
	for(int i=0; i<N; i++)
		if(dfsn[i] == 0) dfs(i);
	if(sn[0] == sn[1]){
		puts("inf");
		return 0;
	}

	vector<int> sAdj[10000];
	int sIn[10000] = {0};
	for(int i=0; i<N; i++){
		for(int j: adj[i]){
			if(sn[i] != sn[j]){
				sAdj[sn[i]].push_back(sn[j]);
				sIn[sn[j]]++;
			}
		}
	}

	bool cycle[10000] = {false}, overflow[10000] = {false};
	int val[10000] = {0};
	val[sn[0]] = 1;
	queue<int> Q;
	for(int i=0; i<SN; i++)
		if(sIn[i] == 0) Q.push(i);

	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		if(sSize[curr] > 1 && val[curr] > 0) cycle[curr] = true;

		for(int next: sAdj[curr]){
			if(cycle[curr]) cycle[next] = true;
			if(overflow[curr]) overflow[next] = true;
			val[next] += val[curr];
			if(val[next] >= MOD){
				val[next] %= MOD;
				overflow[next] = true;
			}
			if(--sIn[next] == 0) Q.push(next);
		}
	}
	if(cycle[sn[1]]) puts("inf");
	else printf((overflow[sn[1]] ? "%09d\n" : "%d\n"), val[sn[1]]);
}