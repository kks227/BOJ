#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, A[7], val[7];

void dfs(int k){
	if(k == M){
		for(int i=0; i<M; i++)
			printf("%d ", val[A[i]]);
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
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	sort(val, val+N);
	N = unique(val, val+N) - val;
	dfs(0);
}