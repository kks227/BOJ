#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, M, S, E;
	vector<P> adj[10000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		A--; B--;
		adj[A].push_back(P(B, C));
		adj[B].push_back(P(A, C));
	}
	scanf("%d %d", &S, &E);
	S--; E--;

	int lo = 0, hi = 1000000001;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		queue<int> Q;
		bool visited[10000] = {0};
		Q.push(S);
		visited[S] = true;
		while(!Q.empty()){
			if(visited[E]) break;
			int curr = Q.front();
			Q.pop();
			for(auto &p: adj[curr]){
				int next = p.first;
				if(!visited[next] && p.second >= mid){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		if(visited[E]) lo = mid;
		else hi = mid;
	}
	printf("%d\n", lo);
}