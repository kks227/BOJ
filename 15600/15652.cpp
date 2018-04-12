#include <cstdio>
using namespace std;

int N, M, A[8];

void dfs(int k, int l){
	if(k == M){
		for(int i=0; i<M; i++)
			printf("%d ", A[i]+1);
		puts("");
		return;
	}
	for(int i=l; i<N; i++){
		A[k] = i;
		dfs(k+1, i);
	}
}

int main(){
	scanf("%d %d", &N, &M);
	dfs(0, 0);
}