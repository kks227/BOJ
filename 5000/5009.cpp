#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 200;

int dcnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){ return n%2 ? n-1 : n+1; }

int dfs(int curr){
	dfsn[curr] = ++dcnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sn[curr] = SN++;
		while(1){
			int family = S.top();
			S.pop();
			finished[family] = true;
			if(family == curr) break;
			sn[family] = sn[curr];
		}
	}
	return result;
}

int main(){
	int N, C[200][2], R[200][199];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int P;
		scanf("%d", &P);
		for(int j=0, k=0; j<3; j++){
			if(j == P) continue;
			C[i][k++] = j;
		}
		for(int j=0; j<N-1; j++){
			scanf("%d", &R[i][j]);
			R[i][j]--;
		}
	}

	for(int T=N-2; T>=0; T--){
		for(int i=0; i<N; i++){
			for(int j=0; j<2; j++){
				for(int k=0; k<2; k++){
					if(C[i][j] != C[R[i][T]][k]) continue;
					int p = i*2 + j, q = R[i][T]*2 + k;
					adj[oppo(p)].push_back(q);
					adj[oppo(q)].push_back(p);
				}
			}
		}

		for(int i=0; i<N*2; i++)
			if(dfsn[i] == 0) dfs(i);
		bool result = true;
		for(int i=0; i<N; i++){
			if(sn[i*2] == sn[i*2+1]){
				result = false;
				break;
			}
		}
		if(!result){
			printf("%d\n", T+1);
			return 0;
		}

		SN = dcnt = 0;
		fill(dfsn, dfsn+N*2, 0);
		fill(finished, finished+N*2, false);
	}
	puts("0");
}