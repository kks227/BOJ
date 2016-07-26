#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, cnt, dfsn[300], SN, sn[300];
bool adj[300][300], finished[300], sAdj[300][300];
vector<vector<int>> scc;
stack<int> S;

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next=0; next<N; next++){
		if(curr != next && adj[curr][next]){
			if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
			else if(!finished[next]) result = min(result, dfsn[next]);
		}
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
		scc.push_back(newScc);
		SN++;
	}
	return result;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		memset(adj, 0, sizeof(adj));
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%1d", &adj[i][j]);

		cnt = SN = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, 0, sizeof(finished));
		scc.clear();
		for(int i=0; i<N; i++)
			if(dfsn[i] == 0) GetSCCsByDFS(i);

		memset(sAdj, 0, sizeof(sAdj));
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(adj[i][j] && sn[i] != sn[j])
					sAdj[sn[i]][sn[j]] = true;

		for(int i=0; i<SN; i++){
			queue<int> Q;
			bool sVisited[300] = {0};
			for(int j=0; j<SN; j++){
				if(sAdj[i][j]){
					Q.push(j);
					sVisited[j] = true;
				}
			}
			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				for(int next=0; next<SN; next++)
					if(sAdj[curr][next]){
						sAdj[i][next] = false;
						if(!sVisited[next]){
							Q.push(next);
							sVisited[next] = true;
						}
					}
			}
		}

		int cnt = 0;
		for(int i=0; i<SN; i++){
			if(scc[i].size() > 1) cnt += scc[i].size();
			for(int j=0; j<SN; j++)
				if(sAdj[i][j]) cnt++;
		}
		printf("%d\n", cnt);
		for(int i=0; i<SN; i++)
			if(scc[i].size() > 1){
				for(int j=0; j<scc[i].size()-1; j++)
					printf("%d %d\n", scc[i][j]+1, scc[i][j+1]+1);
				printf("%d %d\n", scc[i].back()+1, scc[i][0]+1);
			}
		for(int i=0; i<SN; i++)
			for(int j=0; j<SN; j++)
				if(sAdj[i][j])
					printf("%d %d\n", scc[i][0]+1, scc[j][0]+1);
		puts("");
	}
}