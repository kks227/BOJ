#include <cstdio>
using namespace std;

int N, M, A[8];
bool used[8];

void dfs(int k){
	if(k == M){
		for(int i=0; i<M; i++)
			printf("%d ", A[i]+1);
		puts("");
		return;
	}
	for(int i=0; i<N; i++){
		if(!used[i]){
			used[i] = true;
			A[k] = i;
			dfs(k+1);
			used[i] = false;
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	dfs(0);
}