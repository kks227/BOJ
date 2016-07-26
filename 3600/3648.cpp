#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1000;

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
	while(scanf("%d %d", &N, &M) > 0){
		cnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sccNum, 0, sizeof(sccNum));
		memset(finished, 0, sizeof(finished));
		for(int i=0; i<N*2; i++)
			adj[i].clear();

		for(int i=0; i<M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			a = a<0 ? -(a+1)*2 : a*2-1;
			b = b<0 ? -(b+1)*2 : b*2-1;
			if(a==0 || b==1) a = b;
			else if(a==1 || b==0) b = a;
			adj[oppo(a)].push_back(b);
			adj[oppo(b)].push_back(a);
		}
		for(int i=0; i<N*2; i++)
			if(dfsn[i] == 0) DFS(i);
		bool result = true;
		for(int i=0; i<N; i++)
			if(sccNum[i*2] == sccNum[i*2+1]){
				result = false;
				break;
			}
		puts(result ? "yes" : "no");
	}
}