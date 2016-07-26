#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 10000;

int N, M, cnt, scc, dfsn[MAX*2], sccNum[MAX*2];
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
		sccNum[curr] = scc++;
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
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A = A<0 ? -(A+1)*2 : A*2-1;
		B = B<0 ? -(B+1)*2 : B*2-1;
		adj[oppo(A)].push_back(B);
		adj[oppo(B)].push_back(A);
	}
	for(int i=0; i<N*2; i++)
		if(dfsn[i] == 0) DFS(i);
	for(int i=0; i<N; i++)
		if(sccNum[i*2] == sccNum[i*2+1]){
			puts("0");
			return 0;
		}
	puts("1");

	int result[MAX];
	memset(result, -1, sizeof(result));
	P p[MAX*2];
	for(int i=0; i<N*2; i++)
		p[i] = P(sccNum[i], i);
	sort(p, p+N*2);
	for(int i=N*2-1; i>=0; i--){
		int var = p[i].second;
		if(result[var/2] == -1) result[var/2] = !(var%2);
	}
	for(int i=0; i<N; i++)
		printf("%d ", result[i]);
}