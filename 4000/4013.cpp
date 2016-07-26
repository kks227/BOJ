#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int cnt, dfsn[500000], SN, sn[500000];
bool finished[500000];
vector<int> adj[500000];
stack<int> S;

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result == dfsn[curr]){
		while(1){
			int t = S.top();
			S.pop();
			sn[t] = SN;
			finished[t] = true;
			if(t == curr) break;
		}
		SN++;
	}
	return result;
}
 
int main(){
	int N, M, cash[500000];
	bool hasRest[500000] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
	}
	for(int i=0; i<N; i++)
		if(dfsn[i] == 0) GetSCCsByDFS(i);

	for(int i=0; i<N; i++)
		scanf("%d", cash+i);
	int start, P;
	scanf("%d %d", &start, &P);
	start--;
	for(int i=0; i<P; i++){
		int p;
		scanf("%d", &p); 
		hasRest[p-1] = true;
	}

	vector<int> sAdj[500000];
	int sStart, sCash[500000] = {0}, sIndegree[500000] = {0};
	bool sHasRest[500000] = {0};
	for(int i=0; i<N; i++){
		int si = sn[i];
		sCash[si] += cash[i];
		if(hasRest[i]) sHasRest[si] = true;
		if(i == start) sStart = si;

		for(int j: adj[i]){
			int sj = sn[j];
			if(si == sj) continue;

			sAdj[si].push_back(sj);
			sIndegree[sj]++;
		}
	}

	queue<int> Q;
	int sMax[500000];
	bool sCal[500000] = {0};
	for(int i=0; i<SN; i++){
		sMax[i] = sCash[i];
		if(i == sStart) sCal[i] = true;
		if(sIndegree[i] == 0) Q.push(i);
	}
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(int next: sAdj[curr]){
			if(sCal[curr]){
				sMax[next] = max(sMax[next], sMax[curr] + sCash[next]);
				sCal[next] = true;
			}
			if(--sIndegree[next] == 0) Q.push(next);
		}
	}

	int result = 0;
	for(int i=0; i<SN; i++)
		if(sHasRest[i] && sCal[i]) result = max(result, sMax[i]);
	printf("%d\n", result);
}