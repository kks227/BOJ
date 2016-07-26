#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
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
	for(int t=0; t<T; t++){
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		cnt = scc = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sccNum, 0, sizeof(sccNum));
		memset(finished, 0, sizeof(finished));
		for(int i=0; i<(N+M)*2; i++)
			adj[i].clear();

		for(int i=0; i<K; i++){
			int A, B, C, D, p, q, r, s;
			scanf("%d %d %d %d", &A, &B, &C, &D);
			if(A == C && B == D) continue;

			if(A < C){ p = (N+B)*2-1; q = (N+D)*2-1; }
			else{ p = (N+B-1)*2; q = (N+D-1)*2; }
			if(B < D){ r = A*2-1; s = C*2-1; }
			else{ r = (A-1)*2; s = (C-1)*2; }
			if(A == C){
				adj[oppo(r)].push_back(s);
				adj[oppo(s)].push_back(r);
			}
			else if(B == D){
				adj[oppo(p)].push_back(q);
				adj[oppo(q)].push_back(p);
			}
			else{
				adj[oppo(p)].push_back(q);
				adj[oppo(q)].push_back(p);
				adj[oppo(p)].push_back(r);
				adj[oppo(r)].push_back(p);
				adj[oppo(s)].push_back(q);
				adj[oppo(q)].push_back(s);
				adj[oppo(s)].push_back(r);
				adj[oppo(r)].push_back(s);
			}
		}
		for(int i=0; i<(N+M)*2; i++)
			if(dfsn[i] == 0) DFS(i);
		bool result = true;
		for(int i=0; i<N+M; i++)
			if(sccNum[i*2] == sccNum[i*2+1]){
				result = false;
				break;
			}
		puts(result ? "Yes" : "No");
	}
}