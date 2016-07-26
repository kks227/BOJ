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
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x = x<0 ? -(x+1)*2 : x*2-1;
		y = y<0 ? -(y+1)*2 : y*2-1;
		adj[oppo(x)].push_back(y);
		adj[oppo(y)].push_back(x);
	}
	for(int i=0; i<N*2; i++)
		if(dfsn[i] == 0) DFS(i);
	for(int i=0; i<N; i++)
		if(sccNum[i*2] == sccNum[i*2+1]){
			puts("OTL");
			return 0;
		}
	puts("^_^");
}