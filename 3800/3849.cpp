#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 20000;

int dcnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){ return n%2 ? n-1 : n+1; }

inline void addEdge(int p, int q){
	adj[oppo(p)].push_back(q);
	if(p != q) adj[oppo(q)].push_back(p);
}

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
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		int A[10000];
		getchar();
		for(int i=0; i<N; i++){
			switch(getchar()){
				case 'A': A[i] = 0; break;
				case 'G': A[i] = 1; break;
				case 'T': A[i] = 2; break;
				default : A[i] = 3;
			}
			if(i < N-1) addEdge(i*4, (i+1)*4);
		}
		for(int i=0; i<M; i++){
			int L, K[10000];
			scanf("%d:", &L);
			for(int j=0; j<L; j++)
				scanf("%d", K+j);
			for(int j=0; j<L/2; j++){
				int a = A[K[j]], b = A[K[L-j-1]];
				int p = K[j]*4+1, q = K[L-j-1]*4+1, r = p+2, s = q+2;
				switch((b-a+4)%4){
					case 0:
					addEdge(p, oppo(q));
					addEdge(oppo(p), q);
					addEdge(r, oppo(s));
					addEdge(oppo(r), s);
					break;

					case 1:
					addEdge(p, q);
					addEdge(p, oppo(s));
					addEdge(oppo(p), r);
					addEdge(oppo(p), oppo(q));
					break;

					case 2:
					addEdge(p, p);
					addEdge(q, q);
					addEdge(r, s);
					addEdge(oppo(r), oppo(s));
					break;

					default:
					addEdge(p, q);
					addEdge(p, s);
					addEdge(oppo(p), oppo(r));
					addEdge(oppo(p), oppo(q));
				}
			}
		}

		for(int i=0; i<N*4; i++)
			if(dfsn[i] == 0) dfs(i);
		bool result = true;
		for(int i=0; i<N*2; i++){
			if(sn[i*2] == sn[i*2+1]){
				result = false;
				break;
			}
		}
		puts(result ? "YES" : "NO");

		SN = dcnt = 0;
		fill(dfsn, dfsn+MAX*2, 0);
		fill(finished, finished+MAX*2, false);
		for(int i=0; i<N*4; i++)
			adj[i].clear();
	}
}