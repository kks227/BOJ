#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200;

// [pos][val]
int N, A[MAX], B[MAX];
bool adj[MAX][MAX], visited[MAX];

bool dfs(int a){
	visited[a] = true;
	for(int b=0; b<N; b++){
		if(!adj[a][b]) continue;
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int M, lo[MAX] = {0}, hi[MAX];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		fill(adj[i], adj[i]+N, true);
	fill(hi, hi+N, N-1);
	for(int i=0; i<M; i++){
		int o, x, y, v;
		scanf("%d %d %d %d", &o, &x, &y, &v);
		x--; y--; v--;
		for(int j=0; j<N; j++){
			if(j < x || j > y) adj[j][v] = false;
			else if(o == 1) hi[j] = min(hi[j], v);
			else lo[j] = max(lo[j], v);
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<lo[i]; j++) adj[i][j] = false;
		for(int j=hi[i]+1; j<N; j++) adj[i][j] = false;
	}

	int cnt = 0;
	fill(A, A+N, -1);
	fill(B, B+N, -1);
	for(int i=0; i<N; i++){
		if(A[i] == -1){
			fill(visited, visited+N, false);
			if(dfs(i)) cnt++;
		}
	}
	if(cnt < N) puts("-1");
	else{
		for(int i=0; i<N; i++)
			printf("%d ", A[i]+1);
	}
}