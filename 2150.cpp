#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V, E, cnt, dfsn[10000];
vector<int> adj[10000];
bool finished[10000];
stack<int> S;
vector<vector<int>> scc;

int DFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, DFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result == dfsn[curr]){
		vector<int> curscc;
		while(1){
			int n = S.top();
			S.pop();
			curscc.push_back(n);
			finished[n] = true;
			if(n == curr) break;
		}
		sort(curscc.begin(), curscc.end());
		scc.push_back(curscc);
	}
	return result;
}

int main(){
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		adj[A-1].push_back(B-1);
	}
	for(int i=0; i<V; i++)
		if(dfsn[i] == 0) DFS(i);
	sort(scc.begin(), scc.end());
	printf("%d\n", scc.size());
	for(auto& curscc: scc){
		for(int curr: curscc)
			printf("%d ", curr+1);
		puts("-1");
	}
}