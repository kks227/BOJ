#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, matchA[100], matchB[100];
vector<int> adj[100];
bool visited[100];

bool BipertiteMatch(int A){
	for(int B: adj[A]){
		if(visited[B]) continue;
		visited[B] = true;
		if(matchB[B]==-1 || BipertiteMatch(matchB[B])){
			matchA[A] = B;
			matchB[B] = A;
			return true;
		}
	}
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &N, &M);
		int longest = 0;
		for(int i=0; i<N; i++)
			adj[i].clear();
		for(int i=0; i<M; i++){
			int S, E, A;
			scanf("%d %d %d", &S, &E, &A);
			longest = max(longest, E);
			for(int j=0; j<A; j++){
				int Q;
				scanf("%d", &Q);
				for(int k=S; k<E; k++)
					adj[Q-1].push_back(k);
			}
		}
		for(int i=0; i<N; i++)
			sort(adj[i].begin(), adj[i].end());
		memset(matchA, -1, sizeof(matchA));
		memset(matchB, -1, sizeof(matchB));
		int received = 0;
		for(int i=0; i<N; i++){
			memset(visited, 0, sizeof(visited));
			received += BipertiteMatch(i);
		}
		if(received < N) puts("-1");
		else{
			int result;
			for(result = longest-1; matchB[result] == -1; result--);
			printf("%d\n", result+1);
		}
	}
}