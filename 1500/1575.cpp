#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100;

int M, A[MAX], B[MAX*MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a){
	visited[a] = true;
	for(int b: adj[a]){
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int N, K, R = 0, finished[MAX], result[MAX];
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		scanf("%d", finished+i);
		finished[i]--;
	}
	sort(finished, finished+K);
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int X, Y;
		scanf("%d %d", &X, &Y);
		for(int j=0; j<Y; j++){
			int sub;
			scanf("%d", &sub);
			sub--;
			for(int k=0; k<X; k++)
				adj[sub].push_back(M+k);
		}
		M += X;
	}

	int cnt = 0;
	fill(A, A+MAX, -1);
	fill(B, B+M, -1);
	for(int i=0; i<K; i++){
		fill(visited, visited+MAX, false);
		if(dfs(finished[i])) cnt++;
	}
	for(int i=0; i<MAX && cnt<M; i++){
		if(A[i] != -1) continue;
		fill(visited, visited+MAX, false);
		if(dfs(i)){
			cnt++;
			result[R++] = i;
		}
	}
	if(cnt < M) puts("-1");
	else{
		printf("%d\n", R);
		for(int i=0; i<R; i++)
			printf("%d ", result[i]+1);
	}
}