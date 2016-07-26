#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

long long info[10000], sInfo[10000];
int cnt, dfsn[10000], SN, sn[10000], sSize[10000];
vector<int> adj[10000];
bool finished[10000];
stack<int> S;

long long GCD(long long p, long long q){
	long long r;
	while(q){
		r = p%q;
		p = q;
		q = r;
	}
	return p;
}

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sInfo[SN] = info[S.top()];
		sSize[SN] = 0;
		while(1){
			int t = S.top();
			S.pop();
			finished[t] = true;
			sn[t] = SN;
			sInfo[SN] = GCD(sInfo[SN], info[t]);
			sSize[SN]++;
			if(t == curr) break;
		}
		SN++;
	}
	return result;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		long long L;
		scanf("%d %d %lld", &N, &M, &L);
		for(int i=0; i<N; i++)
			adj[i].clear();
		for(int i=0; i<M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a-1].push_back(b-1);
		}
		for(int i=0; i<N; i++)
			scanf("%lld", info+i);

		SN = cnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, 0, sizeof(finished));
		for(int i=0; i<N; i++)
			if(dfsn[i] == 0) GetSCCsByDFS(i);

		vector<int> sAdj[10000];
		int sIndegree[10000] = {0};
		for(int i=0; i<N; i++)
			for(int j: adj[i])
				if(sn[i] != sn[j]){
					sAdj[sn[i]].push_back(sn[j]);
					sIndegree[sn[j]]++;
				}
		queue<int> Q;
		for(int i=0; i<SN; i++)
			if(sIndegree[i] == 0) Q.push(i);

		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(int next: sAdj[curr]){
				sInfo[next] = GCD(sInfo[next], sInfo[curr]);
				if(--sIndegree[next] == 0) Q.push(next);
			}
		}
		int result = 0;
		for(int i=0; i<SN; i++)
			if(sInfo[i] == L) result += sSize[i];
		printf("%d\n", result);
	}
}