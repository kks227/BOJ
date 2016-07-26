#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int V, E, cnt, root, dfsn[10000];
vector<int> adj[10000];
set<int> cut;

int DFS(int curr){
	dfsn[curr] = ++cnt;
	int result = dfsn[curr], child = 0;
	for(int next: adj[curr]){
		if(dfsn[next] != 0) result = min(result, dfsn[next]);
		else{
			int temp = DFS(next);
			result = min(result, temp);
			if(curr != root && temp >= dfsn[curr]) cut.insert(curr);
			child++;
		}
	}

	if(curr == root && child > 1) cut.insert(curr);
	return result;
}

int main(){
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for(int i=0; i<V; i++)
		if(dfsn[i] == 0){
			root = i;
			DFS(i);
		}
	printf("%d\n", cut.size());
	for(int n: cut)
		printf("%d ", n+1);
}