#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, M, matchA[200], matchB[200];
vector<int> adj[200];
bool visited[200];

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
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int S, D;
		scanf("%d", &S);
		for(int j=0; j<S; j++){
			scanf("%d", &D);
			adj[i].push_back(D-1);
		}
	}
	memset(matchA, -1, sizeof(matchA));
	memset(matchB, -1, sizeof(matchB));
	int result = 0;
	for(int i=0; i<N; i++){
		memset(visited, 0, sizeof(visited));
		result += BipertiteMatch(i);
    }
	printf("%d\n", result);
}