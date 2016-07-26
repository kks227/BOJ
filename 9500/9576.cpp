#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, M, matchA[1000], matchB[1000];
vector<int> adj[1000];
bool visited[1000];

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
		for(int i=0; i<M; i++){
			int A, B;
			scanf("%d %d", &A, &B);
			adj[i].clear();
			for(int j=A-1; j<B; j++)
				adj[i].push_back(j);
		}
		memset(matchA, -1, sizeof(matchA));
		memset(matchB, -1, sizeof(matchB));
		int result = 0;
		for(int i=0; i<M; i++){
			memset(visited, 0, sizeof(visited));
			result += BipertiteMatch(i);
		}
		printf("%d\n", result);
	}
}