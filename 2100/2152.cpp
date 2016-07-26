#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int cnt, dfsn[10000], SN, sn[10000];
bool finished[10000];
vector<int> adj[10000];
stack<int> S;

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
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
		SN++;
	}
	return result;
}
 
int main(){
	int N, M, start, end;
	scanf("%d %d %d %d", &N, &M, &start, &end);
	start--; end--;
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
	}
	for(int i=0; i<N; i++)
		if(dfsn[i] == 0) GetSCCsByDFS(i);

	vector<int> sAdj[10000];
	int sStart, sEnd, sCity[10000] = {0}, sIndegree[10000] = {0};
	for(int i=0; i<N; i++){
		int si = sn[i];
		sCity[si]++;
		if(i == start) sStart = si;
		if(i == end) sEnd = si;
		for(int j: adj[i]){
			int sj = sn[j];
			if(si == sj) continue;
			sAdj[si].push_back(sj);
			sIndegree[sj]++;
		}
	}

	queue<int> Q;
	int sMax[10000];
	bool sVisited[10000] = {0};
	for(int i=0; i<SN; i++){
		sMax[i] = sCity[i];
		if(i == sStart) sVisited[i] = true;
		if(sIndegree[i] == 0) Q.push(i);
	}
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(int next: sAdj[curr]){
			if(sVisited[curr]){
				sMax[next] = max(sMax[next], sMax[curr] + sCity[next]);
				sVisited[next] = true;
			}
			if(--sIndegree[next] == 0) Q.push(next);
		}
	}
	printf("%d\n", sVisited[sEnd] ? sMax[sEnd] : 0);
}