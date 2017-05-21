#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1000;

int cnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){ return n%2 ? n-1 : n+1; }

int dfs(int curr){
	dfsn[curr] = ++cnt;
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
	int N, M;
	while(scanf("%d %d", &N, &M) > 0){
		for(int i=0; i<M; i++){
			int A, B;
			scanf("%d %d", &A, &B);
			A = (A<0 ? -(A+1)*2 : A*2-1);
			B = (B<0 ? -(B+1)*2 : B*2-1);
			adj[oppo(A)].push_back(B);
			adj[oppo(B)].push_back(A);
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
		printf("%d\n", result);

		cnt = SN = 0;
		fill(dfsn, dfsn+MAX*2, 0);
		fill(finished, finished+MAX*2, false);
		for(int i=0; i<N*2; i++)
			adj[i].clear();
	}
}