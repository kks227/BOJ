#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

int N, cnt, adj[1000], dfsn[1000];
bool finished[1000];
int SN, scc[1000], sSize[1000], sAdj[1000];
stack<int> S;
int K, DN, minW[1000], maxW[1000], dp[1000][1001];

int maxPassenger(int pos, int remain){
	if(pos == DN) return 0;
	int &ret = dp[pos][remain];
	if(ret != -1) return ret;

	ret = maxPassenger(pos+1, remain);
	if(remain >= minW[pos]){
		for(int i=minW[pos]; i<=maxW[pos] && i<=remain; i++)
			ret = max(ret, maxPassenger(pos+1, remain-i)+i);
	}
	return ret;
}

int DFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr], next = adj[curr];
	if(dfsn[next] == 0) result = min(result, DFS(next));
	else if(!finished[next]) result = min(result, dfsn[next]);

	if(result >= dfsn[curr]){
		int cnt = 0;
		while(1){
			int n = S.top();
			S.pop();
			cnt++;
			scc[n] = SN;
			finished[n] = true;
			if(n == curr) break;
		}
		sSize[SN++] = cnt;
	}
	return result;
}

void pushW(int curr){
	int next = sAdj[curr];
	if(next==curr || maxW[curr]==0) return;
	maxW[next] += maxW[curr];
	minW[curr] = maxW[curr] = 0;
	pushW(next);
}

bool is0(int n){ return !n; }



int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", adj+i);
		adj[i]--;
	}
	for(int i=0; i<N; i++)
		if(dfsn[i] == 0) DFS(i);
	for(int i=0; i<N; i++)
		sAdj[scc[i]] = scc[adj[i]];

	for(int i=0; i<SN; i++)
		minW[i] = maxW[i] = sSize[i];
	for(int i=0; i<SN; i++)
		pushW(i);
	DN = remove_if(minW, minW+SN, is0) - minW;
	remove_if(maxW, maxW+SN, is0);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxPassenger(0, K));
}