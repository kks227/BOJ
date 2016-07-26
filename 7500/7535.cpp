#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 2000;

int cnt, scc, dfsn[MAX*2], sccNum[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){
	return n%2 ? n-1 : n+1;
}

int DFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, DFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sccNum[curr] = ++scc;
		while(1){
			int family = S.top();
			S.pop();
			finished[family] = true;
			if(family == curr) break;
			sccNum[family] = sccNum[curr];
		}
	}
	return result;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		cnt = scc = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sccNum, 0, sizeof(sccNum));
		memset(finished, 0, sizeof(finished));
		for(int i=0; i<N*2; i++)
			adj[i].clear();

		for(int i=0; i<M; i++){
			int A, B;
			scanf("%d %d", &A, &B);
			A = A*2-1; B = B*2-1;
			adj[A].push_back(oppo(B));
			adj[B].push_back(oppo(A));
			adj[oppo(A)].push_back(B);
			adj[oppo(B)].push_back(A);
		}
		for(int i=0; i<N*2; i++)
			if(dfsn[i] == 0) DFS(i);
		bool result = true;
		for(int i=0; i<N; i++)
			if(sccNum[i*2] == sccNum[i*2+1]){
				result = false;
				break;
			}
		printf("Scenario #%d:\n%suspicious bugs found!\n\n", t, (result?"No s":"S"));
	}
}