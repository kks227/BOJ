#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, A[8], val[8];
bool used[8];

void dfs(int k, int l){
	if(k == M){
		for(int i=0; i<M; i++)
			printf("%d ", val[A[i]]);
		puts("");
		return;
	}
	if(l == N) return;
	for(int i=l; i<N; i++){
		if(!used[i]){
			used[i] = true;
			A[k] = i;
			dfs(k+1, i+1);
			used[i] = false;
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	sort(val, val+N);
	dfs(0, 0);
}