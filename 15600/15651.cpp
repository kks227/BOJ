#include <cstdio>
using namespace std;

int N, M, A[7];

void dfs(int k){
	if(k == M){
		for(int i=0; i<M; i++)
			printf("%d ", A[i]+1);
		puts("");
		return;
	}
	for(int i=0; i<N; i++){
		A[k] = i;
		dfs(k+1);
	}
}

int main(){
	scanf("%d %d", &N, &M);
	dfs(0);
}