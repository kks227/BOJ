#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int V, E, cnt, dfsn[100000];
vector<int> adj[100000];
set<P> cut;

int DFS(int curr, int prev){
	dfsn[curr] = ++cnt;
	int result = dfsn[curr], child = 0;
	for(int next: adj[curr]){
		if(next == prev) continue;
		if(dfsn[next] != 0) result = min(result, dfsn[next]);
		else{
			int temp = DFS(next, curr);
			result = min(result, temp);
			if(temp > dfsn[curr]){
				if(curr < next) cut.insert(P(curr, next));
				else cut.insert(P(next, curr));
			}
			child++;
		}
	}
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
	DFS(0, -1);
	printf("%d\n", cut.size());
	for(auto& p: cut)
		printf("%d %d\n", p.first+1, p.second+1);
}