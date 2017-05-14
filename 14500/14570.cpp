#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, L[200000], R[200000];

void dfs(int curr, long long k){
	if(L[curr] == -1 && R[curr] == -1){
		printf("%d\n", curr+1);
		exit(0);
	}

	if(L[curr] == -1) dfs(R[curr], k);
	else if(R[curr] == -1) dfs(L[curr], k);
	else{
		if(k%2) dfs(R[curr], k/2);
		else dfs(L[curr], k/2);
	}
}

int main(){
	scanf("%d", &N);
	fill(L, L+N, -1);
	fill(R, R+N, -1);
	for(int i=0; i<N; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		if(l != -1) L[i] = l-1;
		if(r != -1) R[i] = r-1;
	}
	long long K;
	scanf("%lld", &K);
	dfs(0, K-1);
}