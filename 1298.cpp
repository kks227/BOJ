#include <cstdio>
#include <cstring>
#include <vector>
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
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		adj[A-1].push_back(B-1);
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